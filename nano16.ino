// 这里的输入和输出是针对Arduino电路板而言
// 定义按键输入针脚号为2号针脚

#include <Servo.h>
Servo servo_1;  //大拇指指     // 创建一个名为 servo_1 的 舵机实例 （名称可随你喜欢命名）
Servo servo_2;//食指
Servo servo_3;//无名指+中指+小指
Servo servo_4;
Servo servo_5;
Servo servo_6;



const int buttonPin_0 = 6;

const int buttonPin_1= 7; //设置第二个按钮

const int buttonPin_2 = 8; //设置第三个按钮

const int buttonPin_3 = 9; //设置第三个按钮

// 定义LED输入针脚号为13号针脚
// 注：此处我们使用的LED神灯是Arduino UNO电路板自带，
// 此神灯对应的针脚号默认为13，此数值不得随意更改，
// 所以这里定义的数值13是为了和默认值相对应。
const int ledPin =  13;
// 定义按键状态变量初始值为0
int buttonState_0 =1;
int buttonState_1=1;

int buttonState_2=1;

int buttonState_3=1;
// 对Arduino电路板或相关状态进行初始化方法
void setup() {
  Serial.begin(9600);

  // 设置ledPin端口为输出端口
  pinMode(ledPin, OUTPUT);
  // 设置buttonPin端口为输入端口
  pinMode(buttonPin_0, INPUT);

  pinMode(buttonPin_1, INPUT);
  
  pinMode(buttonPin_2, INPUT);

  pinMode(buttonPin_3, INPUT);
 // void setup() {
  servo_1.attach(3); // 配置myservo实例的引脚为9
  servo_2.attach(4);
  servo_3.attach(5);
}

// 系统调用，无限循环方法
void loop() {
  // 读取按键状态

  
  buttonState_0= digitalRead(buttonPin_0);
  buttonState_1=digitalRead(buttonPin_1);
  buttonState_2=digitalRead(buttonPin_2);
  
  buttonState_3=digitalRead(buttonPin_3);

  Serial.println(buttonState_0);
  Serial.println(buttonState_1);
  Serial.println(buttonState_2);
  Serial.println(buttonState_3);
  // 检查按键状态，
  // 如果为HIGH，
  // 则点亮LED神灯，
  // 否则熄灭LED神灯。
  if(buttonState_0==LOW){
    // 点亮LED神灯
    Serial.println("button 1 one clicked");
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
//  // 控制所有舵机 从 0度 到 179度 转动
    for (int i = 0; i < 90; i++){
      servo_1.write(180-3*i);
      servo_2.write(180-i*2);
      servo_3.write(2*i);
      //servo_3.write(abs(180-i*2));
      delay(20);}
  }else if(buttonState_1==LOW){ 
    // 点亮LED神灯
    Serial.println("button 2 one clicked");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);

    for (int i = 0; i < 45; i++) {
      servo_1.write(180-i*2);
      delay(100);
    }
  }else if(buttonState_2==LOW) {
    // 点亮LED神灯
    Serial.println("button 3 one clicked");
    digitalWrite(ledPin, HIGH);

    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);

    //delay(5000);
  
    for (int i = 0; i < 90; i++) {
      servo_1.write(180-i*2);
      servo_2.write(180-i*2);
      //servo_3.write(90-i);
      
      delay(50);
    }
  }else if(buttonState_3== LOW) {
    // 点亮LED神灯
    Serial.println("button 4 one clicked");
    digitalWrite(ledPin, HIGH);

    delay(500);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
 
   // servo_2.write(0);
    for (int i = 0; i < 90; i++) {
      servo_1.write(180-i*2);
     
      servo_3.write(90-i);
      
      delay(20);
    }
  }
  delay(500);
}
