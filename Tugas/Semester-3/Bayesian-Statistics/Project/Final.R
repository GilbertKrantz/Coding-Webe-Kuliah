library(coda)
library(rjags)

# Load Function
## SVSS
SVSS_cal <- function(sample) {
  beta <- NULL
  for(l in 1:n.chains){
    beta <- rbind(beta,sample[[l]])
  }
  library(knitr)
  Inc_Prob <- apply(beta!=0,2,mean)
  Q <- t(apply(beta,2,quantile,c(0.5,0.05,0.95)))
  out <- cbind(Inc_Prob,Q)
  kable(round(out,2))
}

## DIC WAIC
DIC_WAIC_cal <- function(model) {
  # Compute DIC
  dic1 <- dic.samples(model,n.iter=n.iter)
  # Compute WAIC
  waic1 <- coda.samples(model, variable.names=c("like"), n.iter=n.iter)
  like1 <- waic1[[1]]
  fbar1 <- colMeans(like1)
  P1 <- sum(apply(log(like1),2,var))
  WAIC1 <- -2*sum(log(fbar1))+2*P1
  
  print(dic1)
  print(WAIC1)
}

# Load Data
df <- read.csv('./ParisHousing.csv')

## Set Dataframe as matrix and split dependent and independent variable 
price <- as.matrix(df$price)
Y <- price
X <- cbind(df$squareMeters, df$numberOfRooms, 
           df$hasYard, df$hasPool, df$floors, 
           df$cityCode, df$numPrevOwners, df$made, 
           df$isNewBuilt, df$hasStormProtector, df$basement, 
           df$attic, df$garage, df$hasStorageRoom, df$hasGuestRoom, df$cityPartRange)
names <- c("price","Square Meters", "Number of Rooms", 
           "Has Yard", "Has Pool", "Number of Floors", 
           "City Code", "Number of Previous Owners", 
           "Year Made", "is Newly Built", "Has Storm Protector", 
           "Basement Area", "Attic Area", "Garage Area", 
           "Has Storage Room", "Has Guest Room", "City Part Range")

## Delete Missing Value
junk <- is.na(rowSums(X))
Y <- Y[!junk]
X <- X[!junk,]

## Standardize Covariates
X <- as.matrix(scale(X))


# Model 1
## Put Data in JAGS Format
n <- length(Y)
p <- ncol(X)

data <- list(Y=Y,X=X,n=n,p=p)
params <- c("alpha","beta")
burn <- 100
n.iter <- 2000
n.chains <- 3

## Make Jags Model
model_string <- textConnection("model{
# Likelihood
for(i in 1:n){
Y[i] ~ dnorm(alpha+mu[i],taue)
mu[i] <- inprod(X[i,],beta[])
}
# Priors
for(j in 1:p){
beta[j] ~ dnorm(0,0.001)
}
alpha ~ dnorm(0,0.001)
taue ~ dgamma(0.1, 0.1)

# WAIC calculations
for(i in 1:n){
like[i] <- dnorm(Y[i],mu[i],taue)
}
}")

### Set Initial Value
inits = list()

inits$alpha = rnorm(1)
for(i in 1:p) {
  inits$beta[i] = rnorm(1)
}
inits$taue = 10

### Compile Model
model1 <- jags.model(model_string,data = data, n.chains=n.chains,quiet=TRUE, inits = inits)

### Update Model
update(model1, burn)

### Get Posterior Samples from the model
samples1 <- coda.samples(model1, variable.names=params, n.iter=n.iter)

DIC_WAIC_cal(model1)

round(cor(df),2) 
