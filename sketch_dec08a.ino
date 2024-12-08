#define Parameter1 400 // Average monthly consumption
#define Parameter2 200 // Free grid units
#define Parameter3 12   // Cost per unit for excess grid usage
#define Parameter4 15   // Cost per unit for alternative energy

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Calculate costs
  int gridCost = 0;
  if (Parameter1 > Parameter2) {
    gridCost = (Parameter1 - Parameter2) * Parameter3;
  }

  int altEnergyCost = Parameter1 * Parameter4;

  // Calculate optimal strategy
  int altEnergyUsage = min(Parameter1, Parameter2);
  int gridUsage = Parameter1 - altEnergyUsage;
  int optimalCost = altEnergyUsage * Parameter4 + gridUsage * Parameter3;

  // Print results
  Serial.print("Grid cost: ");
  Serial.println(gridCost);
  Serial.print("Alternative energy cost: ");
  Serial.println(altEnergyCost);
  Serial.print("Optimal cost: ");
  Serial.println(optimalCost);

  // Calculate savings
  int savings = min(gridCost, altEnergyCost) - optimalCost;
  Serial.print("Savings: ");
  Serial.println(savings);

  while (true); // Keep the program running
}
