import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import random
import webbrowser

taks_list = ['Git Hub Wikipedia' , 'open chrome' , 'What is the Time' , "open YouTube"]
random.shuffle(taks_list)

#speak function
def speak(audio):
    engine = pyttsx3.init()
    engine.say(audio)
    engine.runAndWait()

# function to wish a user
def Wish_user():
  hour = int(datetime.datetime.now().hour)

  if hour>= 0 and hour< 12:
    speak('Good morning Sir !')

  elif hour>= 12 and hour<18:
    speak('Good Afternoon Sir')

  else:
    speak('Good Evening Sir')
  speak('I am your Voice Assistant. You can aske me for help any time. To begain say Git hub Wikipedia.')


# function to take audio command from user
def take_user_command():
  r = sr.Recognizer()
  with sr.Microphone() as source:
    print('Listening..')
    r.pause_threshold  = 1
    audio = r.listen(source)

  try:
    print("Recognizing")
    query = r.recognize_google(audio , language = ' en-in')
    print(f"You said: {query}\n")

  except Exception as e:
    # print(e)
    print("say that again please..")
    speak('I didn\'t hear you. say that again please ! if you want me to stop, say stop.')
    speak(f'if you are confuse what to say just say{taks_list[0]}')
    return "None" 
  return query



# tasks that this Assistant can do
if __name__ == "__main__":
    Wish_user()
    while True:
        query = take_user_command().lower()
        if "wikipedia" in query:
            speak('searching wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query , sentences=2)
            speak('Wikipedia says.')
            print(results)
            speak(results)

        elif 'the time' in query:
            strTIme = datetime.datetime.now().strftime('%H:%M:%S')
            print(strTIme)
            speak(f'Sir the time is {strTIme}')
            
        elif "open youtube" in query:
            speak('openning youtube')
            webbrowser.open("youtube.com")

        elif "open google" in query:
            speak('openning google')
            webbrowser.open("google.com") 

        elif 'stop' in query:
            speak('ok ! you can ask for help anytime , sir!')
            exit()
        else:
            random.shuffle(taks_list)
            speak(f'task didn\'t matched. try saying {taks_list[0]}')
            
        