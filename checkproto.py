import message_pb2


msg = message_pb2.Values()
msg.param.append(3.14)
msg.param.append(6.28)

msgStr = msg.SerializeToString()

print(msgStr)