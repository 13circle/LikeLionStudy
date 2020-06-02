# Hello YEE! (Simple stdout)
print('YEE \n')

# Simple conditional statements for integers
x = 15
if x < 18:
    print('U kint enter dat site, dude!')
elif x < 40:
    print('U r in a proper age!')
else:
    print('Sir... r ya serious?')
print()

# Simple loop statments
print('Captain: Sergeant, Report the current status.')
print('Sergeant: Sir! Nuke launch detected, sir! We gotta get outta here!')
print('Captain: ....Wat?')
print('Sergeant: Nuke approaching! Impact expected in')
n = 5
while n > 0:
    print('Sergeant: ' + str(n) + '!')
    n = n - 1
print('Captain: I see those funeral boys dancing in front of me...')
print('\'KABOOM\' \n')

# Simple stdin
name = input('Enter ur name:')
if name == 'YEE':
    print('Dat name is not 4 u, dude')
else:
    print(name + ', you have successfully verified your name.')
print()

# Type classification & conversion
var1 = 'YEE'
var2 = 222
print(type(var1))
print(type(var2))
print(str(var2) + ' = ' + str(float(var2)))
print()

