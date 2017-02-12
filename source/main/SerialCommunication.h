
namespace SOFT561
{
  namespace Arduino
  {
    enum SerialMessage {
      up,
      down,
      left,
      right
    };
    class SerialCommunication
    {
      private:
        SerialMessage _in_message;
        SerialMessage _out_message;
        
      public:
        SerialCommunication(int baud);
        
        void push(SerialMessage msg);
        SerialMessage pop();
    };
  }
}

