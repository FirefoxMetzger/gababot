
namespace SOFT561
{
  namespace Arduino
  {
    enum SerialMessage {
      none=0,
      up=1,
      down=2,
      left=3,
      right=4
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

