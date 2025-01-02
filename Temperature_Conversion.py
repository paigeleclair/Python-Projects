#Paige Leclair
#Program that can convert temperatures 
#=========================================================================
def conversions():
    print('This program will convert temps for you')
    print('Here are your options:')
    print('1: Convert from Celsius to Farenheit')
    print('2: Convert from Celsius to Kelvin')
    print('3: Convert from Fahrenheit to Celsius')
    print('4: Convert from Farenheit to Kelvin')
    print('5: Convert from Kelvin to Celsius')
    print('6: Convert from Kelvin to Farenheit')
    
def main():
    conversions()
    number = int(input('Select a number'))
    while number > 6 or number < 1:
        number = int(input('Invalid. Select a number between 1 and 6'))
    temp = int(input('Enter a temperature:'))

    #using conditional form for dictionary 
    dict_choices = {'1': print(f'{temp} degrees celcius is {(Celsius_to_Fahrenheit(temp)):.2f} degrees Fahrenheit') \
                    if number == 1 else None ,\
                    '2': print(f'{temp} degrees celcius is {Celsius_to_Kelvin(temp):.2f} degrees Kelvin')\
                    if number == 2 else None,\
                    '3': print(f'{temp} degrees Fahrenheit is {Fahrenheit_to_Celsius(temp):.2f} degrees Celsius')\
                    if number == 3 else None,\
                    '4': print(f'{temp} degrees Fahrenheit is {Fahrenheit_to_Kelvin(temp):.2f} degrees Kelivin') \
                    if number == 4 else None,\
                    '5': print(f'{temp} degrees Kelvin {Kelvin_to_Celsius(temp):.2f} degrees Celsius ')\
                    if number == 5 else None,\
                    '6': print(f'{temp} degrees Kelvin {Kelvin_to_Fahrenheit(temp):.2f}degrees Fahrenheit') \
                    if number == 6 else None}

    again = input('Would you like to select another option:')
    while again.lower() != 'no':
        main()
        again = input('Would you like to select another option:')

        
    
        

   
def Celsius_to_Fahrenheit(temp):
    F = (9 / 5) * temp +32
    return F
def Celsius_to_Kelvin(temp):
    K = temp + 273.15
    return K

def Fahrenheit_to_Celsius(temp):
    C = (5 / 9) * (temp - 32)
    return C

def Fahrenheit_to_Kelvin(temp):
    K = (5 / 9) * (temp - 32) + 273.15
    return K

def Kelvin_to_Celsius(temp):
    C = temp - 273.15
    return C
def Kelvin_to_Fahrenheit(temp):
    F = (9 / 5) * (temp - 273.15) +32
    return F
    
    
    
    
main()

