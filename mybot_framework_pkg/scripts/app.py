from flask import Flask, render_template, jsonify
import rospy
import threading
from std_msgs.msg import Int32, String

app = Flask(__name__)

robot_status = "Sending room..."
last_sent_room = -1  

rospy.init_node('web_controller', anonymous=True)
pub = rospy.Publisher('room_number', Int32, queue_size=10)

def status_callback(msg):
    global robot_status
    robot_status = msg.data
    rospy.loginfo(f"{robot_status}")

rospy.Subscriber('room_status', String, status_callback)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/move/<int:room>', methods=['POST'])
def move_robot(room):
    global last_sent_room

    if room == last_sent_room:
        return jsonify({"status": "error", "message": f"Already moving to Room {room}"})

    rospy.loginfo(f"Moving to Room {room}")
    pub.publish(room)
    last_sent_room = room  

    return jsonify({"status": "success", "message": f"Moving to Room {room}"})

@app.route('/status', methods=['GET'])
def get_status():
    return jsonify({"status": "success", "message": robot_status})

def ros_spin_thread():
    rospy.spin()

if __name__ == '__main__':
    thread = threading.Thread(target=ros_spin_thread)
    thread.daemon = True  
    thread.start()
    app.run(host='0.0.0.0', port=5000, debug=True)
