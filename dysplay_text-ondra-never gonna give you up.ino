#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

  vypisText("We're no strang-ers to love");
  delay(2000);
  vypisText("You know the rules and so do I");
  delay(2000);
  vypisText("A full commitment's what I'm ");
  delay(2000);
  vypisText("thinking of You wouldn't get");
  delay(2000);
  vypisText("this from any other guy");
  delay(2000);
  vypisText("I just wanna tell you how");
  delay(2000);
  vypisText("I'm feeling Gotta make you ");
  delay(2000);
  vypisText("understand");
  delay(1000);
  vypisText("Never gonna let you down");
  delay(2000);
  vypisText("Never gonna run around");
  delay(2000);
  vypisText("and desert you");
  delay(1000);
  vypisText("Never gonna make you cry");
  delay(2000);
  vypisText("Never gonna say goodbye");
  delay(2000);
  vypisText("Never gonna tell a lie ");
  delay(2000);
  vypisText("and hurt you");
  delay(1000);
  vypisText("We've known each other ");
  delay(2000);
  vypisText("for so long");
  delay(1000);
  vypisText("Your heart's been aching");
  delay(2000);
  vypisText("but you're too shy to say it");
  delay(2000);
  vypisText("Inside we both know");
  delay(2000);
  vypisText("what's been going on");
  delay(2000);
  vypisText("We know the game and ");
  delay(2000);
  vypisText("we're gonna play it");
  delay(2000);
  vypisText("And if you ask me how ");
  delay(2000);
  vypisText("I'm feeling");
  delay(1000);
  vypisText("Don't tell me you're ");
  delay(2000);
  vypisText("too blind to see");
  delay(2000);
  vypisText("Never gonna give you up");
  delay(2000);
  vypisText("Never gonna let you down");
  delay(2000);
  vypisText("Never gonna run around");
  delay(2000);
  vypisText("and desert you");
  delay(2000) ;
  vypisText("Never gonna make you cry");
  delay(2000);
  vypisText("Never gonna say goodbye");
  delay(2000);
  vypisText("Never gonna tell a…");
  delay(2000);
  vypisText("YEEEES A JEBU NA TO");
  delay(2000);
}
void vypisText(String ch) {
  lcd.clear();
  if (ch.length() <= 16) {
    lcd.setCursor(0, 0);
    for (int i = 0; i < ch.length(); i++) {
      lcd.setCursor(i, 0);
      lcd.print(ch.charAt(i));

    }
  } else {
    for (int i = 0; i < 16; i++) {
      lcd.setCursor(i, 0);
      lcd.print(ch.charAt(i));
    }
    for (int i = 0; i < ch.length() - 16; i++) {
      lcd.setCursor(i, 1);
      lcd.print(ch.charAt(16 + i));

    }

  }
}
