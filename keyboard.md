## 

## Assembly Manual: DGMusika Assembly Guide

## LIST OF COMPONENTS

**1) Acrylic Boards (with smooth edges):** Used as the base for mounting
the components like Arduino, keyboard matrix, and amplifier. Provides a
durable, transparent platform with clean, smooth edges for safety and
aesthetic purposes.

## **2) Arduino UNO**: Microcontroller board that controls entire system.

## **3) 2×6 Keyboard Matrix (PCB):** Soldered with header connectors; white and black plastic keys mounted on top.

**4) Rubber Strips(Silicone keypad):** A 2×6 silicone rubber keypad that
provides tactile feedback and completes the circuit when keys are
pressed.

**5) Screws (M2.5, M2.7, M3)**

**6) Plastic supports (sleeves)**

## **7) Keys (Black and White Plastic Keys one octave):** 12 plastic keys mounted on the keyboard matrix for user interaction.

## **8) Amplifier:** Soldered with header connectors; used to amplify audio signals from the Arduino.

## **9) Speaker:** Outputs the audio signals as sound.

**10) Jumper Wires:** Used to directly connect components(Arduino,
Amplifier, Matrix)

- **Male-to-Female** **--** For connecting Arduino male pins to module
  header**s.**

**11) USB Cable (Type A to Type B):** Powers the Arduino and allows
uploading code.

**[COMPONENTS DESCRIPTION]{.underline}**

**ACRYLIC BOARDS**

Acrylic boards are lightweight, transparent plastic sheets often used as
enclosures, mounting bases, or protective covers in electronics
projects. In this setup, a smooth-edged acrylic board is used as the
baseplate to mount key components such as the keyboard matrix, Arduino,
and speaker module. The material is durable, easy to drill for screws
and stand-offs, and offers good visibility and aesthetics for
demonstration or educational kits. The smooth edges help avoid injuries
and improve the overall finish of the product.

![](media/image1.jpeg){width="4.981944444444444in"
height="1.9041666666666666in"}

**ARDUINO UNO**

The Arduino UNO plays a crucial role as the central controller that ties
together all of the components. It manages the inputs from the keyboard
matrix and sends audio signals to the PAM8403 amplifier, which then
drives the speaker.

![](media/image2.jpeg){width="3.220833333333333in"
height="1.7333333333333334in"}

### **1.** **Reading Input from the 2×6 Keyboard Matrix**

**Function:** The Arduino **scans** the 12 keys on the keyboard matrix
(connected to pins D2 to D9) and detects which key is pressed.

**How it works:**

- The keyboard matrix has **2 rows** and **6 columns**. Pressing a key
  completes a circuit between a specific row and column.

- The Arduino sequentially activates each row while checking the column
  lines for a signal.

- If a column reads LOW while a row is set LOW, the Arduino determines
  which key is pressed.

  **Output:** The Arduino identifies the key and triggers an action
  (play sound).

  **2. Controlling Audio**

  **Function:** Once the Arduino knows which key was pressed, it decides
  what sound to play and sends a signal to the PAM8403 amplifier via pin
  D11.

  **How it works:**

<!-- -->

- The Arduino generates an audio signal on D11. It is a PWM signal
  (using the tone() function)

<!-- -->

- To produce a tone, Arduino uses its PWM pins to output a square wave
  (for audio signals like beeps or tones).

  **3. PAM8403 Audio Amplifier**

  **Function:** The Arduino sends the audio signal to the PAM8403
  amplifier via pin D11.

  **How it works:**

<!-- -->

- The PAM8403 is a low-power audio amplifier that needs an audio input
  (typically a PWM or analog signal).

<!-- -->

- The Arduino outputs a PWM signal (which can represent the audio) to
  the PAM8403.

<!-- -->

- The PAM8403 amplifies this signal to a level that can drive a speaker.

**2×6 KEYBOARD MATRIX PCB**

It is the user input interface, meaning it allows us to interact with
the system by pressing buttons. The Arduino reads which button is being
pressed and responds accordingly (by playing a tone).The **2×6 keyboard
matrix** lets the user send **commands or selections** to the Arduino by
pressing one of 12 keys.

**Structure:**

- Grid of 2 rows and 6 columns (12 keys total).

- Each key lies at a row-column intersection.

  **Advantage:**

- Instead of 12 separate wires, only 8 Arduino pins are used (2 for rows
  and 6 for columns).

  **Build Note:**

- The matrix is **soldered and mounted with black and white plastic
  keys,** for clear visibility and durability.

  ![](media/image3.jpeg){width="6.19375in"
  height="1.1465277777777778in"}

  **RUBBER STRIPS:**

  A silicone rubber keypad with a 2×6 matrix layout is positioned
  directly over the contact pads on the PCB. Each dome on the keypad
  contains a conductive carbon pill that, when pressed, completes the
  circuit by bridging the PCB contacts. This mechanism provides both
  electrical connectivity and tactile feedback. For proper
  functionality, the keypad must be precisely aligned with the PCB
  layout. It can be secured in place using a plastic top cover, adhesive
  backing, or integrated support posts in the device enclosure. During
  operation, pressing a key produces a soft tactile response or sound,
  indicating that the input has been successfully registered.

  ![](media/image4.jpeg){width="6.531944444444444in"
  height="1.6701388888888888in"}

  **KEYS (BLACK AND WHITE PLASTIC KEYS)**

These are the actual physical keys pressed by the user to trigger
sounds.

**Function:**

- Each key makes a contact between a specific row and column on the
  keyboard matrix when pressed.

**Build Note:**

- All 12 keys are securely mounted on the matrix PCB for ease of use.

- White and black color differentiation improves usability.

![](media/image5.jpeg){width="4.404166666666667in"
height="1.176388888888889in"}

**PAM8403 AUDIO AMPLIFIER**

The PAM8403 is a **Class-D audio amplifier** that increases the audio
signal strength from the Arduino to a level suitable for driving a
speaker.

**Note:** ![](media/image6.png){width="2.5618055555555554in"
height="1.9256944444444444in"}The PAM8403 amplifier is soldered with
connectors, making it easier to connect to other components without the
need for additional soldering.

**How it Works:**

**1.** Arduino generates a weak audio signal on pin D11.

**2**. This signal is too soft to drive a speaker directly.

**3.** The PAM8403 amplifier boosts this signal to a loud, clear level.

**4.** The amplified output is then sent to the speaker.

- **Why It's Needed:**

<!-- -->

- The Arduino alone cannot deliver enough current for the speaker,
  resulting in a weak, distorted sound, or potentially damaging the
  Arduino pin. The amplifier ensures the audio is loud and clear.

<!-- -->

- **Power Requirement:**

<!-- -->

- Runs on 5V(same as Arduino).

- Current drawn: \~ 20--30mA without a load, more when the speaker is
  active.

  **SPEAKER**

  A speaker is an output device that converts electrical audio signals
  into sound. In our project, the speaker plays the tones or sounds
  generated by the Arduino and amplified by the PAM8403 amplifier.

  **Function:** The **speaker's main job** is to produce sound loud
  enough to be heard clearly. The Arduino sends an audio signal (as a
  PWM tone), the PAM8403 amplifies it, and the **speaker plays the
  sound**.

  ![](media/image7.jpeg){width="4.044444444444444in"
  height="1.4597222222222221in"}

  **How It Works:**

<!-- -->

- **PWM Signal from Arduino:** The Arduino uses the tone() function to
  create a PWM square wave on pin D11. This waveform represents sound at
  a specific frequency (pitch).

<!-- -->

- **Signal Amplification:** The signal is sent to the PAM8403 amplifier,
  which increases its voltage and current so it\'s strong enough to
  drive the speaker.

<!-- -->

- **Sound Production:** The amplified signal reaches the speaker,
  causing its internal diaphragm to vibrate rapidly. These vibrations
  create sound waves in the air.

  **JUMPER WIRES**

  **Jumper wires** are used to connect all components. Only
  male-to-female jumper wires are used throughout this setup, including
  for the amplifier and speaker.

  **Type Used:**

###  Only **Male-to-Female Jumper Wires** are used for all connections (including the amplifier and speaker),ensuring quick and stable plug-in assembly.

![](media/image8.jpeg){width="4.697916666666667in"
height="1.054861111111111in"}

**USB CABLE (Type A to B)**

The **USB Cable** serves several important purposes, primarily for
**powering the Arduino** and for **programming** the Arduino.

### **1. Powering the Arduino:**

- The **USB cable** connects the **Arduino UNO** to the computer or a
  USB power source.

- It provides **5V of power** to the Arduino board, which is enough to
  power the board and any components that are connected to it (like the
  keyboard matrix, PAM8403 amplifier, and speaker).

  **2.** **Uploading the Code (Programming the Arduino):**

<!-- -->

- The **USB Cable** also allows us to **upload the program (code)** to
  the Arduino.

- Through the USB connection, the Arduino IDE on the computer
  communicates with the Arduino board and sends the code that controls
  the inputs from the keyboard matrix and the outputs to the amplifier
  and speaker.

###  **Cable Type:**

The Arduino UNO uses a **USB Type B** cable (the square connector) on
the Arduino side, and a **USB Type A** (standard USB connector) on the
computer or power source side.

### ![](media/image9.jpeg){width="2.5861111111111112in" height="1.601388888888889in"}

**[STEP-BY-STEP ASSEMBLY INSTRUCTIONS]{.underline}**

### **Step 1: Prepare Acrylic Base**

- Unwrap the acrylic base and clear all holes.

- Place the Arduino UNO on the top-left section.

- Secure using M3×12 screws and M3 nuts.

### **Step 2: Mount the Keyboard Matrix PCB**

- Align the 2×6 matrix PCB to the base holes.

- Place 3 standoffs per screw under the PCB to support it.

- Fix using M2.5×30 screws, M3×25 sleeve nuts, and M2.5 nuts.

### **Step 3: Mount the Plastic Keys**

- Position the black & white keys properly over the PCB.

- Ensure proper alignment for tactile feedback.

- Fix with M2.5×35 screws, M3×25 sleeve nuts, and M2.5 nuts.

  **Step 4: Connect Arduino to 2×6 Keyboard Matrix**

<!-- -->

- **Type of Wire:** Male-to-Female Jumper Wires

<!-- -->

- **Steps:**

  - Connect the rows of the keyboard matrix to D2 and D3 on the Arduino
    (use male-to-female jumper wires).

  - Connect the columns of the keyboard matrix to D4 to D9 on the
    Arduino (use male-to-female jumper wires).

  - This setup allows the Arduino to detect which key is pressed.

### **Step 5: Connect Arduino to PAM8403 Audio Amplifier**

- **Type of Wire:** Male-to-Female Jumper Wires

- **Steps:**

  - Connect the Arduino's D11 pin to the **input** pin (INR) on the
    **PAM8403 amplifier using a male-to-female jumper wire.**

  - This will send the audio signal (PWM signal) from the Arduino to the
    amplifier.

### **Step 6: Power the PAM8403 Amplifier**

- **Type of Wire:** Male-to-Female Jumper Wires

- **Steps:**

- Connect the **5V pin** on the Arduino to the **VCC pin** on the
  PAM8403 amplifier (use male-to-female jumper wires).

  - Connect the **SGND pin** on the Arduino to the **GND pin** on the
    PAM8403 amplifier (use male-to-female jumper wires).

  - This will provide power to the amplifier from the Arduino.

### **Step 7: Connect PAM8403 to Speaker**

- **Type of Wire:** Male-to-Female Jumper Wires

- **Steps:**

  - Connect the **output pins** on the PAM8403 amplifier to the
    **speaker**.

  - Ensure you connect the **positive** and **negative** terminals from
    the amplifier to the speaker (this may depend on your speaker\'s
    wiring, typically the red/positive wire to the positive output, and
    the black/negative wire to the negative output).

  - This will send the amplified audio signal to the speaker for sound
    output.

    **NOTE:** Right Channel Only

<!-- -->

- **Arduino D11** → PAM8403 Right Channel Input (R IN)

- **Speaker** → PAM8403 Right Output (R+) and Right Ground (R-)

### **Explanation:**

- Since we are using **R+** and **R-** pins for the speaker, it means we
  are driving **mono sound** using the **right channel input (R IN)**.

- **R+** will carry the amplified audio signal from the PAM8403, and
  **R-** will be the ground reference for the speaker.

### **Step 8: Power the Arduino via USB Cable**

- **Type of Wire:** USB Type A to B cable

- **Steps:**

  - Connect the **USB cable** (Type B) from the **Arduino** to your
    **computer** or a **USB power source**.

  - This will provide **5V power** to the Arduino and allow you to
    upload your, program.

#### **Step 5: Install Arduino IDE**

- Download from
  [arduino.cc/software](https://www.arduino.cc/en/software)

- Install on your laptop.

####  Step 6: Upload Code

- Connect Arduino UNO to laptop using USB.

- Open Arduino IDE.

- Load the. ino code file (see below).

- Select Board: Arduino UNO, choose correct COM Port, then Upload.

####  Step 7: Play!

- Once code is uploaded, pressing each key will play a tone through the
  speaker.

  **CIRCUIT DIAGRAM:**

  ![](media/image10.png){width="7.6090277777777775in"
  height="5.548611111111111in"}

  **CONCLUSION**

  This project shows how to use an Arduino UNO, a 2×6 keyboard matrix,
  and a PAM8403 amplifier to create a simple audio system. The Arduino
  reads the keyboard input and generates sound signals, which the
  PAM8403 amplifier boosts to play through a speaker. This setup
  demonstrates how to combine basic components to create an interactive
  system that produces sound based on user input.
