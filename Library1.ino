#include <dummy.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// Wifi network station credentials
#define WIFI_SSID "my_wifi"
#define WIFI_PASSWORD "my_wifi_password"
// Telegram BOT Token (Get from Botfather)
#define BOT_TOKEN "5487826983:AAHM-NBNme4EQoQewS6iDJbb9aVUcohZw14"
const unsigned long BOT_MTBS = 10; // mean time between scan messages

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime;          // last time messages' scan has been done


void handleNewMessages(int numNewMessages)
{ 
  
  Serial.print("handleNewMessages ");
  Serial.println(numNewMessages);
  
  
  for (int i = 0; i < numNewMessages; i++)
  {
        String link ;
       telegramMessage &msg = bot.messages[i];
       Serial.println("Received " + msg.text);
       String chat_id = bot.messages[i].chat_id;
       String text = bot.messages[i].text;
       String from_name = bot.messages[i].from_name;
    
    if (from_name == "")
      from_name = "Guest";

  if (text == "/mathsnotes")
    {
      String keyboardJson = "[[\"maths_module1\", \"maths_module2\"],[\"maths_module3\"],[\"/listofsubject\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Select the module you want.", "", keyboardJson, true);
    }

  if (text == "/ntnotes")
    {
      String keyboardJson = "[[\"nt_module1\", \"nt_module2\"],[\"nt_module3\"],[\"/listofsubject\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Select the module you want.", "", keyboardJson, true);
    }
  
  if (text == "/ednotes")
    {
      String keyboardJson = "[[\"ed_module1\", \"ed_module2\"],[\"ed_module3\"],[\"/listofsubject\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Select the module you want.", "", keyboardJson, true);
    }
  
  if (text == "/dsdnotes")
    {
      String keyboardJson = "[[\"dsd_module1\", \"dsd_module2\"],[\"dsd_module3\"],[\"/listofsubject\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Select the module you want.", "", keyboardJson, true);
    }
  
  if (text == "/conotes")
    {
      String keyboardJson = "[[\"co_module1\", \"co_module2\"],[\"co_module3\"],[\"/listofsubject\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Select the module you want.", "", keyboardJson, true);
    }
    
  if (text == "/penotes")
    {
      String keyboardJson = "[[\"pe_module1\", \"pe_module2\"],[\"pe_module3\"],[\"/listofsubject\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Select the module you want.", "", keyboardJson, true);
    }

 



  if (text == "maths_module1")
  { link += "SORRY\n";
    link += "Not found in server \n";
    link += "You can try Finding any other notes\n";
    bot.sendMessage(msg.chat_id, link, "Markdown");
  }

  if (text == "maths_module2")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/151";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   
  }

  if (text == "maths_module3")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/115";
    bot.sendMessage(msg.chat_id, link, "Markdown");
  }

  if (text == "ed_module1")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/37";
    bot.sendMessage(msg.chat_id, link, "Markdown");
    link = "https://t.me/ECE3rdSemRnsitNotes2021/38";
    bot.sendMessage(msg.chat_id, link, "Markdown");

  }

  if (text == "ed_module2")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/91";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   
  }

  if (text == "ed_module3")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/129";
    bot.sendMessage(msg.chat_id, link, "Markdown");

  }

  if (text == "nt_module1")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/136";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   

  }

  if (text == "nt_module2")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/137";
    bot.sendMessage(msg.chat_id, link, "Markdown");

  }

  if (text == "nt_module3")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/138";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   

  }

  if (text == "dsd_module1")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/44";
    bot.sendMessage(msg.chat_id, link, "Markdown");
    

  }

  if (text == "dsd_module2")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/90";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   
  }

  if (text == "dsd_module3")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/103";
    bot.sendMessage(msg.chat_id, link, "Markdown");

  }

  if (text == "co_module1")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/73";
    bot.sendMessage(msg.chat_id, link, "Markdown");

  }

  if (text == "co_module2")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/86";
    bot.sendMessage(msg.chat_id, link, "Markdown");

  }

  if (text == "co_module3")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/85";
    bot.sendMessage(msg.chat_id, link, "Markdown");
    
  }

  if (text == "pe_module1")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/89";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   

  }

  if (text == "pe_module2")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/87";
    bot.sendMessage(msg.chat_id, link, "Markdown");
   

  }

  if (text == "pe_module3")
  {
    link = "https://t.me/ECE3rdSemRnsitNotes2021/88?single";
    bot.sendMessage(msg.chat_id, link, "Markdown");


  }



  if (text == "/listofsubject")
    {
    String welcome = "Welcome to ESP32 Telegram Bot library, " + from_name + ".\n\n";
      welcome += "This the list of subject you can select.\n\n";
      welcome += "/mathsnotes\n";
      welcome += "/ntnotes\n";
      welcome += "/ednotes\n";
      welcome += "/dsdnotes\n";
      welcome += "/conotes\n";
      welcome += "/penotes\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    
  }

  if (text == "/start")
    {
    String welcome = "Welcome to ESP32 Telegram Bot library, " + from_name + ".\n\n";
      welcome += "This the list of subject you can select.\n\n";
      welcome += "/mathsnotes\n";
      welcome += "/ntnotes\n";
      welcome += "/ednotes\n";
      welcome += "/dsdnotes\n";
      welcome += "/conotes\n";
      welcome += "/penotes\n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    
  }
  
  }


}

void bot_setup()
{   //bot menu configuration
  const String commands = F("["
                            "{\"command\":\"/listofsubject\", \"description\":\"LIST OF SUBJECT\"},"
                            "{\"command\":\"/mathsnotes\", \"description\":\"Maths notes\"},"
                            "{\"command\":\"/ntnotes\", \"description\":\"Network theory\"},"
                            "{\"command\":\"/ednotes\", \"description\":\"Electronic Devices\"},"
                            "{\"command\":\"/dsdnotes\", \"description\":\"Digital System Design\"},"
                            "{\"command\":\"/conotes\", \"description\":\"Computer Organisation\"},"
                            "{\"command\":\"/penotes\", \"description\":\"Power Electronis\"}"
//                            "{\"command\":\"/cpcnotes\", \"description\":\"Constitution and Cyber Security\"}" // no comma on last command
                            "]");
  bot.setMyCommands(commands);
 
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  // attempt to connect to Wifi network:
  Serial.print("Connecting to Wifi SSID ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nWiFi connected. IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Retrieving time: ");
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

 bot_setup();
}

void loop()
{
  if (millis() - bot_lasttime > BOT_MTBS)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }


    bot_lasttime = millis();
    
  }
}
