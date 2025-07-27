// class HouseDownPaymentCalculator {

//     private double annualSalary;
//     private double portionSaved;
//     private double totalCost;

//     private final double DOWN_PAYMENT_RATE = 0.25;
//     private final double ANNUAL_RETURN_RATE = 0.04;

//     // Constructor
//     public HouseDownPaymentCalculator(double annualSalary, double portionSaved, double totalCost) {
//         this.annualSalary = annualSalary;
//         this.portionSaved = portionSaved;
//         this.totalCost = totalCost;
//     }

//     // Method to calculate months needed
//     public double calculateMonthsToSave() {
//         double downPayment = totalCost * DOWN_PAYMENT_RATE;
//         double currentSavings = 0.0;
//         double monthlySalary = annualSalary / 12.0;
//         double monthlyReturnRate = ANNUAL_RETURN_RATE / 12.0;
//         double months = 0;

//         while (currentSavings < downPayment) {
//             currentSavings += monthlySalary * portionSaved;
//             currentSavings += currentSavings * monthlyReturnRate;
//             months++;
//         }

//         return months;
//     }

//     // Display summary
//     public void displaySummary() {
//         System.out.println("Annual Salary: " + annualSalary);
//         System.out.println("Portion Saved: " + (portionSaved * 100) + "%");
//         System.out.println("Total House Cost: " + totalCost);
//         System.out.println("Months to Save for Down Payment: " + calculateMonthsToSave());
//     }

// }

// public class a1 {
//     public static void main(String[] args) {
//         // Example: ₹120,000 salary, 10% savings, ₹1,000,000 house
//         HouseDownPaymentCalculator calculator = new HouseDownPaymentCalculator(120000, 0.10, 1000000);
//         calculator.displaySummary();
//     }
// }

class HouseDownPaymentCalculator {

    double annualSalary;
    double portionSaved;
    double totalCost;

    final double DOWN_PAYMENT_RATE = 0.25;
    final double ANNUAL_RETURN_RATE = 0.04;

    // Constructor
    public HouseDownPaymentCalculator(double annualSalary, double portionSaved, double totalCost) {
        this.annualSalary = annualSalary;
        this.portionSaved = portionSaved;
        this.totalCost = totalCost;
    }

    // Method to calculate months needed
    public int calculateMonthsToSave() {
        double downPayment = totalCost * DOWN_PAYMENT_RATE;
        double currentSavings = 0.0;
        double monthlySalary = annualSalary / 12.0;
        double monthlyReturnRate = ANNUAL_RETURN_RATE / 12.0;
        int months = 1;

        while (currentSavings < downPayment) {
            months++; // Increment first to ensure full month is counted
            currentSavings += monthlySalary * portionSaved;
            currentSavings += currentSavings * monthlyReturnRate;
        }

        return months;
    }

    // Display summary
    public void displaySummary() {
        System.out.println("Annual Salary: " + annualSalary);
        System.out.println("Portion Saved: " + (portionSaved * 100) + "%");
        System.out.println("Total House Cost: " + totalCost);
        System.out.println("Months to Save for Down Payment: " + calculateMonthsToSave());
    }
}

class HouseDownPaymentCalculatorWithRaise extends HouseDownPaymentCalculator {

    private double semiAnnualRaise;

    public HouseDownPaymentCalculatorWithRaise(double annualSalary, double portionSaved, double totalCost,
            double semiAnnualRaise) {
        super(annualSalary, portionSaved, totalCost);
        this.semiAnnualRaise = semiAnnualRaise;
    }

    @Override
    public int calculateMonthsToSave() {
        double downPayment = totalCost * DOWN_PAYMENT_RATE;
        double currentSavings = 0.0;
        double monthlySalary = annualSalary / 12.0;
        double monthlyReturnRate = ANNUAL_RETURN_RATE / 12.0;
        int months = 0;

        while (currentSavings < downPayment) {
            months++;
            currentSavings += monthlySalary * portionSaved;
            currentSavings += currentSavings * monthlyReturnRate;

            if (months % 6 == 0) {
                annualSalary += annualSalary * semiAnnualRaise;
                monthlySalary = annualSalary / 12.0;
            }
        }

        return months;
    }
}

public class a1 {
    public static void main(String[] args) {
        // Example: ₹120,000 salary, 10% savings, ₹1,000,000 house
        HouseDownPaymentCalculator calculator = new HouseDownPaymentCalculator(120000, 0.10, 1000000);

        System.out.println("Months to Save for Down Payment: " + calculator.calculateMonthsToSave());
        // calculator.displaySummary();

        HouseDownPaymentCalculatorWithRaise raiseCalc = new HouseDownPaymentCalculatorWithRaise(120000, 0.10, 1000000,
                0.03);

        System.out.println("With Raise: " + raiseCalc.calculateMonthsToSave());
    }

}
