#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>
#include "message.pb.h"

using namespace std;

int main(int argc, char *argv[]) {
  const string endpoint = "tcp://*:1101";

  // initialize the 0MQ context
  zmqpp::context context;

  // generate a pull socket
  zmqpp::socket_type type = zmqpp::socket_type::pull;
  zmqpp::socket socket (context, type);

  // bind to the socket
  cout << "Binding to " << endpoint << "..." << endl;
  socket.bind(endpoint);

// open the connection
  // cout << "Opening connection to " << endpoint << "..." << endl;
  // socket.connect(endpoint);

  // receive the message

  cout << "Receiving message..." << endl;
  
  //zmqpp::message message;

  // decompose the message 
  
  //TO receive string from python
  // string message;
  // socket.receive(message);

  //TO receive bytes from python
  char buff [256];
  int nbytes = zmq_recv (socket, buff, 256, 0); assert (nbytes != -1);
  ipc::Values response;
  response.ParseFromString(buff);


  cout << "Received message" << endl;
  for(int i=0; i<response.param_size(); ++i) {
    printf("Index(%d): Value(%f)\n", i, response.param(i));
  }
  
  //string text;
  //int number;
  //message << "Hello";
  //socket.send(message);
  //cout << "Received text:" << message << endl;
  cout << "Finished." << endl;
}
