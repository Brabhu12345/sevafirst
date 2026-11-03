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
# who is affected
The primary group affected includes people with limited hand mobility due to physical disabilities, injuries, or conditions that restrict their ability to grip and manipulate objects.

The problem is relevant in homes, rehabilitation centres, healthcare environments, and workplaces where hand movements are essential for everyday activities.

The affordability challenge is particularly relevant in communities where access to advanced assistive technologies is limited by financial constraints.

Additionally, industries, laboratories, and research environments can benefit from affordable robotic manipulation systems for remote operations and human-robot interaction.

Our project explores a low-cost approach that could contribute to making basic robotic manipulation technology more accessible.
# what is innovative 
The key innovation is the integration of real-time human hand gesture tracking with a five-finger robotic hand through wireless communication.

Unlike conventional robotic hands that rely primarily on manual controls, our system aims to provide a more natural control experience by translating human finger movements directly into robotic movements.

Its distinguishing features include:

- Five-finger independent control: Each finger is operated by an individual servo motor.
- Real-time gesture mirroring: Human finger movements are translated into corresponding robotic movements.
- Wireless communication: Uses Wi-Fi and an ESP8266 NodeMCU instead of a direct wired control connection.
- Low-cost construction: Uses affordable electronic components and a homemade mechanical structure.
- Expandable design: Provides a foundation for future improvements in assistive robotics and remote manipulation.

Rather than depending on expensive commercial robotic hardware, this project demonstrates a practical, budget-friendly approach using commonly available components and technologies.
# how solution works
The robotic hand is designed to provide an affordable approach to assisting people with limited hand mobility. In practical use, a person could wear a compatible hand-tracking device or use a camera to capture their hand gestures, allowing the robotic hand to reproduce those movements remotely.

This could help users perform basic gripping and object-handling tasks in situations where natural hand movement is difficult or unavailable. It could also be adapted for remote manipulation in workplaces, laboratories and environments where direct human interaction with objects is inconvenient or potentially unsafe.

By combining gesture-based control with low-cost electronic components, the project aims to make robotic manipulation technology more accessible, particularly in communities where expensive robotic systems may not be affordable.

The current prototype demonstrates the core concept of gesture-controlled robotic movement and provides a foundation for future development into practical assistive and remote-operation applications.
# stage of solution
The project has reached the working prototype stage. The five-finger robotic hand has been mechanically assembled using servo motors, threads and rubber-band return mechanisms. An ESP8266 NodeMCU successfully controls the fingers through wireless Wi-Fi commands. The control interface has also been tested, demonstrating the movement of individual robotic fingers. The project is currently being refined to improve movement accuracy, synchronization and real-time gesture mirroring.
# benifits and impacts
The primary beneficiaries are people with limited hand mobility due to disabilities, injuries or other physical conditions. The proposed system could help them perform basic gripping and object-handling activities through gesture-controlled robotic movements, potentially supporting greater independence in everyday tasks.

Rehabilitation centres, assistive technology researchers and engineering students could also benefit by using this project as a foundation for developing affordable robotic assistance systems.

Industries and laboratories could explore adapting the technology for remote handling tasks, particularly where direct human interaction with objects is difficult or unsafe.

The expected impact includes encouraging affordable assistive technology development, supporting research into human-robot interaction and creating opportunities to make basic robotic manipulation systems more accessible to communities with limited resources.
# budget
Total Estimated Project Budget: ₹3,360 (Approximately ₹3,400).

Cost Breakdown:

- 2 ESP8266 NodeMCU: ₹800
- 2 Arduino Uno: ₹960
- 5 Servo Motors: ₹900
- 3 Phone Chargers: ₹300 (estimated)
- 3 USB Cables: ₹150 (estimated)
- Wires and Construction Materials: ₹250 (estimated)

Total: ₹3,360
# expand
The solution can be expanded by improving its mechanical design, movement accuracy, durability and wireless connectivity. Future versions could use lightweight, stronger materials and more advanced control systems to provide smoother and more precise finger movements.

The system could be further developed into an affordable assistive device for people with limited hand mobility, with personalized controls based on individual needs. It could also be adapted for remote object handling in industries, laboratories and environments where direct human interaction is difficult or unsafe.

Production costs could be reduced through locally available materials, simplified designs and affordable electronic components. The design could be shared with schools, engineering institutions, rehabilitation centres and innovation communities to encourage further development and wider adoption.

In the long term, the project could evolve into a modular robotic manipulation platform with applications in assistive technology, education, research and remote operations.
#proof and details
Project: Wi-Fi Enabled Five-Finger Gesture-Controlled Robotic Hand

Hardware: 2 ESP8266 NodeMCU boards, 2 Arduino Uno boards, 5 servo motors, 3 phone chargers and 3 USB cables.

Technology: Wi-Fi communication, browser-based control interface and human hand gesture tracking.

Mechanical Design: Homemade lightweight structure using cardboard, threads and rubber bands.

Function: Reproduces human finger movements through wireless servo motor control.

Applications: Assistive technology, remote manipulation, rehabilitation research and human-robot interaction.

Development Stage: Working Prototype.

Estimated Total Budget: ₹3,360 (approximately ₹3,400).
# who accepts and how localised 
People with limited hand mobility, rehabilitation centres, hospitals, educational institutions and industries could adopt or further develop this solution. It can be localized by using affordable components available in local markets, collaborating with nearby engineering colleges and healthcare centres, providing instructions in regional languages such as Tamil, and customizing the design to suit local needs and budgets.