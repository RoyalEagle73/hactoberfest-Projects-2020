#!/usr/bin/env python3

import datetime
import email
import smtplib
import sys

GMAIL_ID = ''
GMAIL_PWD = ''

def usage():
    print("send_reminders: Send meeting reminders")
    print()
    print("invocation: ")
    print("     send_reminders 'date|Meeting Title|Emails' ")
    return 1

def dow(date):
    dateobj = datetime.datetime.strptime(date, r"%d-%m-%Y")
    return dateobj.strftime("%A")

def message_template(date, title):
    message = email.message.EmailMessage()
    weekday = dow(date)
    message['Subject'] = f'Gentle Reminder : "{title}"'
    message.set_content(f'''
    Hi there!

    This is a quick mail just to remind you about: "{title}"
    When : {weekday} | {date}

    See you there.


    This email was automatically sent using Python and Zenity by Ashutosh Krishna.
    '''
    )
    return message

def send_message(message, emails):
    s = smtplib.SMTP('smtp.gmail.com',587)
    s.starttls()
    s.login(GMAIL_ID,GMAIL_PWD)
    message['From'] = GMAIL_ID
    for email in emails.split(','):
        del message['To']
        message['To'] = email
        s.send_message(message)
    s.quit()
    pass

def main():
    if len(sys.argv) < 2:
        return usage()

    try:
        date, title, emails = sys.argv[1].split('|')
        message  = message_template(date, title)
        send_message(message, emails)
        print("Successfully sent reminder(s) to : ", emails)
    except Exception as e:
        print(f"Failed to send email with : {e}", file = sys.stderr)

if __name__ == "__main__":
    sys.exit(main())
