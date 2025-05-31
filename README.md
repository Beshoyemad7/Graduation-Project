# Graduation Project  
## Autonomous Indoor Delivery Robot

---

### 🧭 Overview  
This Autonomous Indoor Delivery Robot is a self-navigating robotic platform designed to transport items autonomously within indoor environments such as offices, hospitals, and warehouses. Developed as a graduation project, it integrates **ROS (Robot Operating System)** with embedded hardware to achieve real-time mapping, localization, path planning, and obstacle avoidance.  
The robot operates without human intervention, leveraging **LiDAR-based SLAM (Simultaneous Localization and Mapping)** and **sensor fusion** for reliable navigation. Its modular design allows for scalable deployment in various logistics scenarios, from office deliveries to healthcare supply transport.

---

### 🚀 Key Features  

#### 1. Autonomous Navigation & SLAM  
- Real-time environment mapping using **RPLidar A1M8** and **GMapping / SLAM Toolbox** in ROS.  
- Dynamic obstacle avoidance via the **ROS Navigation Stack**.  
- Precise localization with **LiDAR scan matching** and **IMU (MPU6050)** sensor fusion.  

#### 2. Robust Motion Control  
- Closed-loop **PID control** for DC motors with encoder feedback, ensuring smooth and accurate movement.  
- **Cytron MDD3A** motor driver for high-current motor control.  

#### 3. Seamless ROS Integration  
- **rosserial** communication between **ROS Noetic (Ubuntu 20.04)** and **Arduino Mega 2560** for real-time sensor data processing and actuation.  
- **RViz** visualization for real-time monitoring of maps, sensor data, and robot trajectories.  

#### 4. Power & Endurance  
- **12V 12Ah battery** for extended untethered operation.  
- Efficient path planning to optimize energy consumption.  

---

### ⚙️ Technical Specifications  

| Component         | Description                               |
|-------------------|-------------------------------------------|
| **Software**      | ROS Noetic, GMapping, SLAM Toolbox, RViz, rosserial |
| **Microcontroller** | Arduino Mega 2560                       |
| **Sensors**       | RPLidar A1M8 (360° LiDAR), MPU6050 (IMU), Wheel Encoders |
| **Actuation**     | DC Gear Motors, Cytron MDD3A Motor Driver |
| **Power**         | 12V 12Ah Rechargeable Battery             |

---

### 🧩 Applications  
- **Office & Campus Deliveries:** Transporting mail, documents, and small packages.  
- **Healthcare Logistics:** Autonomous delivery of medications and lab samples in hospitals.  
- **Warehouse Automation:** Moving inventory without manual intervention.  
- **Hospitality Services:** Enabling automated room service in hotels.  

---

### 📸 Demo

![Robot Figure](https://drive.google.com/drive/folders/17csFdlqmCzHJfE3e7hhVF4v1qE-0-sWg?usp=sharing)  

📽️ [Watch the demo video](https://drive.google.com/drive/folders/1Bcx0jAtpBURvWV9uA8XrtWkdPH-Lpo9Z?usp=sharing) 

---
