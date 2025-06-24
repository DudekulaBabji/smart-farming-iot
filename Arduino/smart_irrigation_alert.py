import smtplib
import random
import time

def read_soil_moisture():
    # Simulate soil moisture sensor value
    return random.randint(10, 60)

def send_email_alert(moisture_value):
    sender = "your@email.com"
    password = "yourpassword"
    recipient = "recipient@email.com"
    subject = "Soil Moisture Alert"
    body = f"Soil moisture is low: {moisture_value}%\nIrrigation triggered."

    message = f"Subject: {subject}\n\n{body}"

    try:
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        server.login(sender, password)
        server.sendmail(sender, recipient, message)
        server.quit()
        print("Email alert sent successfully.")
    except Exception as e:
        print("Failed to send email:", e)

# Main monitoring loop
for _ in range(5):  # Simulate 5 readings
    moisture = read_soil_moisture()
    print(f"Soil Moisture: {moisture}%")
    if moisture < 25:
        send_email_alert(moisture)
    time.sleep(2)
