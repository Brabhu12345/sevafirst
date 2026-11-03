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