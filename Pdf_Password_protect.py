#importing the necessary libraries
from PyPDF2 import PdfFileWriter, PdfFileReader
import getpass

#function for creating an encrypted pdf file
def secure_pdf(file, password):
      parser = PdfFileWriter()
      pdf = PdfFileReader(file)
      for page in range(pdf.numPages):                 
            parser.addPage(pdf.getPage(page))
      parser.encrypt(password)
      with open(f"encrypted_{file}", "wb") as f: 
           parser.write(f) 
           f.close() 

      print(f"encrypted_{file} Created...") 
      
if __name__=="__main__": 
     file = input("Enter the name of the pdf ( as .pdf): ")
     while(True):
         print("(Note : While entering the password characters are hidden)");
         password = getpass.getpass(prompt="Enter the password: ",stream=None)
         passwordagain=getpass.getpass(prompt="Enter password again: ",stream=None)
         if(password==passwordagain):
              secure_pdf(file, password)
              break;
         else:
              print();
              print("password is not matching......")
              print();
              continue; 
     
