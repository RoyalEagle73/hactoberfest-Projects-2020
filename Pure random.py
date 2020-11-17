# Most of the programming languages or modules generate pseudo random numbers/strings , which means they are based on one algorithm and can be predictable
# but random.org API generates truly random numbers
# here's how it can be implemented in python

import requests

def translator(var):
  if var == 'yes':
    var = 'on'
  elif var == 'no':
    var = 'off'
  else:
    print('invalid input')
    exit()
  return var

n = input('how many strings should be generated? (1-10000): ') or '5'

length = input('enter length (1-20): ') or '6'

inc_num = input('include numbers? (yes/no): ') or 'yes'
inc_num = translator(inc_num)

inc_lower = input('include lower alphabets? (yes/no): ') or 'yes'
inc_lower = translator(inc_lower)

inc_upper = input('include upper alphabets? (yes/no): ') or 'yes'
inc_upper= translator(inc_upper)

uniq = input('characters should be unique (yes/no): ') or 'yes'
uniq = translator(uniq)

# fetch the truely random string
rnd_str = requests.get(f'https://www.random.org/strings/?num={n}&len={length}&digits={inc_num}&upperalpha={inc_upper}&loweralpha={inc_lower}&unique={uniq}&format=plain&rnd=new').text

print('the string(s) are:')
print(rnd_str)
