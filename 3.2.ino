#define light_input A5
#define LED D5

bool lux_state;

void setup() {
    pinMode(light_input, INPUT);
    pinMode(LED, OUTPUT);

}

void loop() {
    
    int input;
 
    input = analogRead(light_input);
    
    // enough light
     if (input > 3000 & !lux_state){
        lux_state = true;
        digitalWrite(LED, HIGH);
        Particle.publish("210_LIGHT_LEVEL", String("high light"), PRIVATE);

    }
    // too little light
    if (input < 3000 & lux_state){
        lux_state = false;
        digitalWrite(LED, LOW);
        Particle.publish("210_LIGHT_LEVEL", String("low light"), PRIVATE);
    }
    delay(5000);
}
