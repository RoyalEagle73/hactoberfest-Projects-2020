# Send-Reminders
We have used Zenity for making a simple GUI for reminder screen and Python to send emails.

To run on Linux, open Terminal and write :
* `chmod +x reminder.sh`
* `./reminder.sh`

To run on Windows, open Git Bash and write : 
* `sh reminder.sh`

This will open up the GUI where you will be asked for Date, Title and Email(s) of the recipient(s). Fill it up and click on OK to send the email.


Note : 
* If required on Windows, please install Zenity from https://github.com/kvaps/zenity-windows/releases/download/v3.20.0-1/zenity-3.20.0_win32-1.exe
* Please update the GMAIL_ID and GMAIL_PWD in send_reminders.py
* If, in any case, the program is not able to send reminder, it will show up the error. Fix it and it will start working.
