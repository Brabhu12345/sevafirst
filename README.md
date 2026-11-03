# sevafirst
# track
Conventional robotic manipulation systems often require expensive hardware and complicated control mechanisms. There is a need for an affordable, accessible system that can translate natural human hand gestures into corresponding robotic hand movements in real time. This project aims to develop a low-cost, Wi-Fi-enabled five-finger robotic hand that mirrors human hand gestures through real-time gesture tracking and wireless communication.
# what prb are u solving 
People with limited hand mobility due to physical disabilities, injuries, or other conditions may face difficulties performing everyday tasks that require gripping, holding, or manipulating objects.

Existing advanced robotic and prosthetic hand systems can be expensive and may involve complicated control mechanisms, making such technologies less accessible to people with limited financial resources.

There is also a need for affordable and intuitive robotic systems that allow humans to control mechanical movements naturally, without relying entirely on buttons, joysticks, or wired controllers.

Our project addresses these challenges by exploring an affordable, gesture-controlled robotic hand that can reproduce human finger movements wirelessly.
# proposed solution 
Our proposed solution is a low-cost, five-finger robotic hand that mirrors human hand movements in real time using computer vision and wireless communication.

A camera captures the user's hand movements, and a computer vision-based tracking system detects the positions and movements of individual fingers. The detected movements are converted into control commands and transmitted wirelessly over Wi-Fi to an ESP8266 NodeMCU microcontroller.

The NodeMCU controls five servo motors, with each motor responsible for one robotic finger. These motors reproduce the corresponding finger movements using a mechanical structure made from lightweight and affordable materials. Threads are used to create finger movement, while rubber bands help return the fingers to their original positions.

The prototype is designed to demonstrate real-time gesture mirroring without requiring physical contact with the robotic hand.

Current stage: A working prototype has been developed, with all five servo motors connected and controlled through wireless commands. The robotic hand responds to control inputs, and the gesture-based control system is being integrated and refined.

The project aims to demonstrate how computer vision, microcontrollers, servo motors, and wireless communication can be combined to create an affordable human-robot interaction system.