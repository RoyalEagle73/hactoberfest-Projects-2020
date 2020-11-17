# -*- coding: utf-8 -*-
"""
Created on Sat Mar 21 16:14:14 2020

"""


num_int=1333
num_str="856"

print("Datatype of int num",type(num_int))
print("Datatype of str before type casting",type(num_str))
num_str=int(num_str)
print("Datatype of str after type casting",type(num_str))
num_sum=num_int+num_str
print("Sum of num int and num str",num_str)
print("Datatype of num sum",type(num_sum))