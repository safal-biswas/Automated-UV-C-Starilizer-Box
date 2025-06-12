# 🔬 Automated UV-C Sterilization Box

An intelligent, contactless sterilization system designed to disinfect frequently used items using UV-C light. Built using **Arduino**, **ultrasonic sensor**, **servo motor**, and **UV-C lamps**, the system ensures safe, timed, and automated disinfection—perfect for daily use in homes, offices, and healthcare settings.

---

## 🚀 Features

- 🤖 **Touchless Operation**: Automatically detects presence and opens the box lid.
- 💡 **UV-C Based Disinfection**: Kills germs and viruses using high-intensity UV-C light.
- ⏱️ **Timed Cycle**: Automatically closes and initiates a 5-minute sterilization process.
- 🔔 **User Feedback**: Alerts the user when disinfection is complete and items are ready.
- 🔐 **Safety First**: UV lights activate only when the box is securely closed.

---

## 🧰 Technologies & Components

- 🧠 **Microcontroller**: Arduino Uno
- 🌊 **Ultrasonic Sensor**: HC-SR04 for motion detection
- 🔁 **Servo Motor**: For automated lid control
- 💡 **UV-C Light Source**: For disinfection
- 🔌 **Power Supply**: 12V DC regulated
- 🧾 **Libraries**: `Servo.h`, `NewPing.h`

---

## 🔧 How It Works

1. When a person approaches, the ultrasonic sensor detects motion.
2. The box lid opens automatically via the servo motor.
3. User places items inside; after a short delay, the lid closes.
4. UV-C lights turn on and run for a preset 5 minutes.
5. A buzzer or LED notifies the user when disinfection is complete.

