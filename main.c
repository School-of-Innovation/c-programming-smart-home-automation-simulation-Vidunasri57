/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 // Function prototypes
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[], int *noMotionCount);
 void toggleLight(int rooms, int lights[], int *lightOnCount);
 void readTemperature(int rooms, int temp[]);
 void checkMotionSensor(int rooms, int motion[], int *noMotionCount, int locks[]);
 void lockUnlockSecurity(int rooms, int locks[]);
 void houseStatusSummary(int rooms, int lights[], int temp[], int motion[], int locks[]);
 void autoLockSystem(int *noMotionCount, int locks[], int rooms);
 void energySavingMode(int *lightOnCount, int rooms);
 
 int main() {
     int rooms;
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
 
     // Arrays to store device states
     int lights[rooms], temp[rooms], motion[rooms], locks[rooms];
     int noMotionCount = 0, lightOnCount = 0;
     
     initializeSystem(rooms, lights, temp, motion, locks, &noMotionCount);
     
     int choice;
     while (1) {
         // Display menu
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n");
         printf("2. Read Temperature\n");
         printf("3. Check Motion Sensor\n");
         printf("4. Lock/Unlock Security System\n");
         printf("5. House Status Summary\n");
         printf("6. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1: toggleLight(rooms, lights, &lightOnCount); energySavingMode(&lightOnCount, rooms); break;
             case 2: readTemperature(rooms, temp); break;
             case 3: checkMotionSensor(rooms, motion, &noMotionCount, locks); autoLockSystem(&noMotionCount, locks, rooms); break;
             case 4: lockUnlockSecurity(rooms, locks); break;
             case 5: houseStatusSummary(rooms, lights, temp, motion, locks); break;
             case 6: printf("Exiting...\n"); return 0;
             default: printf("Invalid choice! Try again.\n");
         }
     }
     return 0;
 }
 
 // Function Definitions
 void initializeSystem(int rooms, int lights[], int temp[], int motion[], int locks[], int *noMotionCount) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;   // Lights OFF
         temp[i] = 22 + (i % 5);  // Assign random temperatures
         motion[i] = 0;   // No motion detected
         locks[i] = 1;     // Doors Locked
     }
     *noMotionCount = 0;
     printf("System initialized.\n");
 }
 
 void toggleLight(int rooms, int lights[], int *lightOnCount) {
     int room;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         lights[room - 1] = !lights[room - 1];
         *lightOnCount += lights[room - 1] ? 1 : -1;
         printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void readTemperature(int rooms, int temp[]) {
     int room;
     printf("Enter room number to check temperature (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Room %d Temperature: %d°C\n", room, temp[room - 1]);
         if (temp[room - 1] > 30) {
             printf("Warning: Room %d is too hot!\n", room);
         }
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void checkMotionSensor(int rooms, int motion[], int *noMotionCount, int locks[]) {
     int room;
     printf("Enter room number to check motion sensor (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         printf("Motion %s in Room %d.\n", motion[room - 1] ? "Detected" : "Not Detected", room);
         if (motion[room - 1] == 0) {
             (*noMotionCount)++;
         } else {
             *noMotionCount = 0;
         }
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void lockUnlockSecurity(int rooms, int locks[]) {
     int room;
     printf("Enter room number to lock/unlock (1-%d): ", rooms);
     scanf("%d", &room);
     if (room >= 1 && room <= rooms) {
         locks[room - 1] = !locks[room - 1];
         printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
     } else {
         printf("Invalid room number!\n");
     }
 }
 
 void houseStatusSummary(int rooms, int lights[], int temp[], int motion[], int locks[]) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
                lights[i] ? "ON" : "OFF",
                temp[i],
                motion[i] ? "Motion Detected" : "No Motion",
                locks[i] ? "Locked" : "Unlocked");
     }
 }
 
 void autoLockSystem(int *noMotionCount, int locks[], int rooms) {
     if (*noMotionCount >= 5) {
         for (int i = 0; i < rooms; i++) {
             locks[i] = 1;
         }
         printf("Auto-lock activated: All rooms locked due to inactivity.\n");
         *noMotionCount = 0;
     }
 }
 
 void energySavingMode(int *lightOnCount, int rooms) {
     if (*lightOnCount == rooms) {
         printf("Energy Saving Mode: All lights are ON for too long. Consider turning some OFF.\n");
     }
 }
 