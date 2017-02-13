
namespace SOFT561
{
  namespace Arduino
  {
    enum SerialMessage {
      none=0,
      up=119,
      down=115,
      left=97,
      right=100
    };

    enum BaudRates {
      
    };
    
    class SerialCommunication
    {
      private:
        SerialMessage _in_message;
        SerialMessage _out_message;

        SerialMessage convertMessage(int msg) const;
        
      public:
        SerialCommunication(int baud);
        
        void push(SerialMessage msg);
        SerialMessage pop();
        void update();
    };
  }
}

