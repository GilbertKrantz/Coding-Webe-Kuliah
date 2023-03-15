
def personInput() :
    name = input("Name\t: ")
    
    while True :
        gender = input("Gender[Male/Female]\t: ")
        
        if gender.lower() in ("male", "female") :
            break
        

    height = float(input("Height\t: "))

    while True :
        heightUnit = input("Height Unit[m/cm]\t: ")
        
        if heightUnit.lower() in ("m", "cm") :
            if heightUnit in "cm" :
                height = height / 100
            break

    weight = float(input("Weight\t: "))

    while True :
        weightUnit = input("Weight Unit[g/kg]\t: ")
        
        if weightUnit.lower() in ("g", "kg") :
            if weightUnit in "g" :
                height /= 1000
            break
    
    return name, gender, height, weight

def BMICalc(weight, height) :
    BMI = weight / height**2

    return BMI

print("<----BMI CALCULATOR---->")
parameter = personInput()

name = parameter[0]
gender = parameter[1]
height = parameter[2]
weight = parameter[3]

BMI = BMICalc(weight, height)

print("\n")

print("BMI RESULT")
print("--------------")
print(name)
print(gender.capitalize())

if gender in 'male' :
    if BMI < 18.5 :
        print("Underweight")
    elif BMI < 25 : 
        print("Healthy Weight")
    elif BMI < 30 :
        print("Overweight")
    else :
        print("Obese")
else :
    if BMI < 17.5 :
        print("Underweight")
    elif BMI < 24 : 
        print("Healthy Weight")
    elif BMI < 28 :
        print("Overweight")
    else :
        print("Obese")
        
input()