#this program extracts information about a given topic from wikipedia 

#importing wikipedia library to use its function
import wikipedia

#Prompt for a topic to be searched on wikipedia 
your_search = input("Enter the Topic:- ")    

#Getting title from wikipedia based on search ..<class 'str'> 
title = wikipedia.search(your_search)[0]     

#Getting the whole page from wikipedia ..<class 'wikipedia.wikipedia.WikipediaPage'>
page = wikipedia.page(title)				 
print(page)

#String of text of content
text = page.content                          
print(text)
