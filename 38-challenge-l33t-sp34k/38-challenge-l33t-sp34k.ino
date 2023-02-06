String input = "Eating trees is great!";

void setup() {
  Serial.begin(9600);
  input.toLowerCase();
  input.replace("a", "4");
  input.replace("e", "3");
  input.replace("i", "1");
  Serial.println(input);
}

void loop() {
  
}
