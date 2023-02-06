String insertNameMsg = "Enter first name";
String insertLastnameMsg = "Enter last name";
String name = "";
String lastname = "";
bool isAskingAgain = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (name == "" && !isAskingAgain) {
    Serial.println(insertNameMsg);
  } else if (lastname == "" && !isAskingAgain) {
    Serial.println(insertLastnameMsg);
  } else if (name != "" && lastname != "") {
    Serial.println("Hello, " + name + " " + lastname);
    Serial.end();
  }

  while (Serial.available() == 0) {}

  if (name == "") {
    name = Serial.readString();
    name.trim();
    isAskingAgain = name == "";
  } else if (lastname == "") {
    lastname = Serial.readString();
    lastname.trim();
    isAskingAgain = lastname == "";
  }
}
