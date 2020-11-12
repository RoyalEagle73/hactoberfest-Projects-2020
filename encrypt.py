"""
File: encrypt.py
Encrypts an input string of lowercase letters and prints
the result.  The other input is the distance value.
"""

def encrypt(clear_text, distance):
	code = ""
	for ch in clear_text:
		ordValue = ord(ch)
		cipherValue = ordValue + distance
		if cipherValue > ord('z'):
			cipherValue = ord('a') + distance - \
						  (ord('z') - ordValue + 1)
		code +=  chr(cipherValue)
	return (code)
	

def main():
	plainText =input("Enter a one-word, lowercase message: ")
	offset = int(input("Enter the distance value: "))
	
	result = encrypt(plainText, offset)
	print("Cleartext: {:5s}. Offset:  {:2d} Ciphertext: {:5s}".format(plainText, offset, result))
	
main()
