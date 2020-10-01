
def swap_case(s):
    result = ""
    for letter in s:
        if letter == letter.upper():
            result += letter.lower()
        else:
            result += letter.upper()
    return result
    
    
    
    

if __name__ == '__main__':

    s = input()
    result = swap_case(s)

    print(result)
    
    #just input : sWAP cASE 
    
    #output: Swap Case
