import zmq
import time

import message_pb2



context = zmq.Context()

#  Socket to talk to server
print("Connecting to server…")
socket = context.socket(zmq.PUSH)
socket.connect("tcp://127.0.0.1:1101")
#socket.bind("tcp://*:1101")

print("Sending message..")

msg = message_pb2.Values()
msg.param.append(3.14)
msg.param.append(6.28)

msgStr = msg.SerializeToString()

print(type(msgStr))

message = socket.send(msgStr)
print("Sent Message")
# print("Message: " , message)

#  Get the reply.
# message = socket.recv()
# print("Received reply %s [ %s ]" % (request, message))

