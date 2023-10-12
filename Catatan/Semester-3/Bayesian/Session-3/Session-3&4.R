### Topic 2: From prior information to posterior inference ###

### Summarizing a posterior
## Plot the distribution
theta <- seq(0, 1, by = 0.001)
y <- 8
n <- 10
a <- b <- 1
posterior <- dbeta(theta, y+a, n-y+b)
plot(theta,posterior,type='l')

posterior_scaled <- posterior/sum(posterior) #scales so that posterior sums to 1
plot(theta,posterior_scaled,type = 'l')

## Point estimators
post_mean <- sum(theta*posterior_scaled) #posterior mean
post_median <- min(theta[which(cumsum(posterior_scaled) >= 0.5)]) #posterior median
map <- theta[which.max(posterior_scaled)] #maximum a posteriori

plot(theta,posterior,type = 'l')
abline(v = c(post_mean,post_median,map), col = c("black","green","red"))

## Posterior standard deviation
post_var <- sum(theta^2*posterior_scaled)-post_mean^2 #posterior variance using variance computing formula
post_sd <- sqrt(post_var) #posterior SD

post_lo <- post_mean-2*post_sd
post_up <- post_mean+2*post_sd

plot(theta,posterior,type = 'l')
abline(v = c(post_lo,post_up), col = c("red","red"))

## Credible intervals
ci <- qbeta(c(0.025,0.975),y+a, n-y+b) #95% credible interval
ci_lo <- ci[1]
ci_up <- ci[2]

plot(theta,posterior,type = 'l')
abline(v = c(ci_lo,ci_up), col = c("red","red"))

## Posterior probability
pbeta(0.5,y+a,n-y+b) #posterior probability that theta < 0.5 (refer to null hypo statement)


### Monte Carlo approximations
# MC sampling
theta <- rbeta(100000,y+a,n-y+b)
# Approximate the posterior mean and SD
mean(theta)
sd(theta)
# Transform to odds
gamma <- theta/(1-theta)
theta2 <- theta^2
# Approximate the posterior mean and SD
mean(gamma)
sd(gamma)


### Conjugate prior 1: Smoking example
S <- 1000000
theta1 <- rbeta(S,3+1,2) #generate theta
theta2 <- rbeta(S,30+1,2)
mean(theta2>theta1) #prob of theta1 > theta2

samp1 <- rnbinom(S,1,prob=1-theta1) #generate Y
samp2 <- rnbinom(S,1,prob=1-theta2)
quantile(samp1,c(0.05,0.5,0.95)) #quantile of Y
quantile(samp2,c(0.05,0.5,0.95))
mean(samp1>30) #prob of Y > 30
mean(samp2>30)