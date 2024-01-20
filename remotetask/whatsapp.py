from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import schedule

# Initialize WhatsApp web URL and target phone number
whatsapp_web_url = 'https://web.whatsapp.com/'
target_phone_number = '+8801568539889'  # Replace with the recipient's phone number
message = 'Good Morning!'

# Function to send the message
def send_message(driver, phone_number, message):
    # Open WhatsApp web with the provided phone number and message
    driver.get(f'https://web.whatsapp.com/send?phone={phone_number}&text={message}')
    time.sleep(10)  # Wait for the page to load

    try:
        # Find the send button and click it to send the message
        send_button = driver.find_element(By.XPATH, '//*[@data-icon="send"]')
        send_button.click()
        print(f"Message sent to {phone_number}!")
    except Exception as e:
        # Handle any exceptions that might occur while sending the message
        print(f"Failed to send message to {phone_number}. Error: {e}")

# Main function
def main():
    # Initialize the Chrome WebDriver with the path to the ChromeDriver executable
    driver = webdriver.Chrome(executable_path='Driver_Path')

    # Open WhatsApp web URL
    driver.get(whatsapp_web_url)

    # Wait for the user to scan the QR code and press Enter to continue
    input('Scan the QR code and press Enter to continue...')

    # Schedule the message to be sent every day at 8 AM
    schedule.every().day.at("08:00").do(send_message, driver, target_phone_number, message)

    # Keep the script running to execute scheduled tasks
    while True:
        schedule.run_pending()  # Check if any scheduled tasks need to be executed
        time.sleep(1)  # Sleep for 1 second to avoid excessive CPU usage

if __name__ == "__main__":
    main()
