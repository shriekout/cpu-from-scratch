import serial
import time

# 아두이노와 연결할 시리얼 포트 설정 (포트 이름은 환경에 따라 다름)
ser = serial.Serial('COM7', 9600, timeout=1)  # Windows 예시
# ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)  # 리눅스/맥 예시

time.sleep(2)  # 아두이노가 리셋되기 때문에 잠시 대기

try:
    while True:
        # 사용자 입력을 받아 아두이노에 전송
        user_input = input("Send to Arduino: ")
        ser.write((user_input + '\n').encode())

        # 아두이노로부터 응답 수신
        response = ser.readline().decode().strip()
        if response:
            print("Received from Arduino:", response)

except KeyboardInterrupt:
    print("Exiting...")

finally:
    ser.close()