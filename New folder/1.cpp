#include <iostream>
#include <cmath>

class HouseDownPaymentCalculator
{
private:
    double annualSalary;
    double portionSaved;
    double totalCost;
    const double downPaymentRate = 0.25;
    const double annualReturnRate = 0.04;

public:
    // Constructor
    HouseDownPaymentCalculator(double salary, double savedPortion, double houseCost)
        : annualSalary(salary), portionSaved(savedPortion), totalCost(houseCost) {}

    // Method to calculate months needed
    int calculateMonthsToSave()
    {
        double downPayment = totalCost * downPaymentRate;
        double currentSavings = 0.0;
        double monthlySalary = annualSalary / 12.0;
        double monthlyReturnRate = annualReturnRate / 12.0;
        int months = 0;

        while (currentSavings < downPayment)
        {
            currentSavings += monthlySalary * portionSaved;
            currentSavings += currentSavings * monthlyReturnRate;
            months++;
        }

        return months;
    }

    void displaySummary()
    {
        std::cout << "Annual Salary:" << annualSalary << std::endl;
        std::cout << "Portion Saved: " << portionSaved * 100 << "%" << std::endl;
        std::cout << "Total House Cost:" << totalCost << std::endl;
        std::cout << "Months to Save for Down Payment: " << calculateMonthsToSave() << std::endl;
    }
};

int main()
{
    // Example: ₹120,000 salary, 10% savings, ₹1,000,000 house
    HouseDownPaymentCalculator calculator(120000, 0.10, 1000000);
    calculator.displaySummary();

    return 0;
}