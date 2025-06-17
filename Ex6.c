int sg_a = 2, sg_b = 3, sg_c = 4, sg_d = 5, sg_e = 6, sg_f = 7, sg_g = 8;

int led_green = 9;
int led_yellow = 10;
int led_red = 11;

// Trạng thái đèn: 0 = xanh, 1 = vàng, 2 = đỏ
int state = 0;
int countdown = 8; // Bắt đầu với đèn xanh: 8 giây

unsigned long lastUpdate = 0;

void clear_segments() {
  digitalWrite(sg_a, HIGH);
  digitalWrite(sg_b, HIGH);
  digitalWrite(sg_c, HIGH);
  digitalWrite(sg_d, HIGH);
  digitalWrite(sg_e, HIGH);
  digitalWrite(sg_f, HIGH);
  digitalWrite(sg_g, HIGH);
}

void display_digit(int num) {
  switch (num) {
    case 0: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW);
            digitalWrite(sg_d, LOW); 
            digitalWrite(sg_e, LOW); 
            digitalWrite(sg_f, LOW); 
            break;

    case 1: digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW); 
            break;

    case 2: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_g, LOW);
            digitalWrite(sg_e, LOW); 
            digitalWrite(sg_d, LOW); 
            break;

    case 3: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW);
            digitalWrite(sg_d, LOW); 
            digitalWrite(sg_g, LOW); 
            break;

    case 4: digitalWrite(sg_f, LOW); 
            digitalWrite(sg_g, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW); 
            break;

    case 5: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_f, LOW); 
            digitalWrite(sg_g, LOW);
            digitalWrite(sg_c, LOW); 
            digitalWrite(sg_d, LOW); 
            break;

    case 6: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_f, LOW); 
            digitalWrite(sg_g, LOW);
            digitalWrite(sg_e, LOW); 
            digitalWrite(sg_c, LOW); 
            digitalWrite(sg_d, LOW); 
            break;

    case 7: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW); 
            break;

    case 8: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW);
            digitalWrite(sg_d, LOW); 
            digitalWrite(sg_e, LOW); 
            digitalWrite(sg_f, LOW); 
            digitalWrite(sg_g, LOW); 
            break;

    case 9: digitalWrite(sg_a, LOW); 
            digitalWrite(sg_b, LOW); 
            digitalWrite(sg_c, LOW);
            digitalWrite(sg_d, LOW); 
            digitalWrite(sg_f, LOW); 
            digitalWrite(sg_g, LOW); 
            break;
  }
}

void setLights(int green, int yellow, int red) {
  digitalWrite(led_green, green);
  digitalWrite(led_yellow, yellow);
  digitalWrite(led_red, red);
}

void setup() {
  // Setup segment pins
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH); // clear segment
  }

  // Setup LEDs
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);

  // Đèn xanh sáng trước
  setLights(HIGH, LOW, LOW);

  // Hiển thị số đếm
  display_digit(countdown);

  lastUpdate = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastUpdate >= 1000) {
    lastUpdate = currentMillis;

    display_digit(countdown);
    countdown--;

    if (countdown < 0) {
      // Chuyển trạng thái đèn
      state = (state + 1) % 3;

      switch (state) {
        case 0: // Xanh
          countdown = 8;
          setLights(HIGH, LOW, LOW);
          break;
        case 1: // Vàng
          countdown = 2;
          setLights(LOW, HIGH, LOW);
          break;
        case 2: // Đỏ
          countdown = 9;
          setLights(LOW, LOW, HIGH);
          break;
      }
    }
  }
}
