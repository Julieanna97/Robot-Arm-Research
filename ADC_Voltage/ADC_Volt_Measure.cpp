#include <iostream>
#include <cmath>

// ADC voltage reference in volts
const double ADC_REFERENCE_VOLTAGE = 5.0;

// ADC resolution in bits
const int ADC_RESOLUTION = 12;

// ADC sampling rate in Hz
const int ADC_SAMPLING_RATE = 100000;

// Length of the robotic arm in meters
const double ROBOTIC_ARM_LENGTH = 1.0;

int main()
{
    // Read ADC value, it can be volts also
    int adc_value = 1234; // Replace with actual ADC reading

    // Calculate the voltage step per second
    double adc_voltage_step_per_second = ADC_REFERENCE_VOLTAGE / pow(2, ADC_RESOLUTION) * ADC_SAMPLING_RATE;

    // Calculate the voltage step per nanosecond
    double adc_voltage_step_per_nanosecond = adc_voltage_step_per_second / 1e9;

    // Calculate the frequency in Hertz
    double frequency = ADC_SAMPLING_RATE / pow(2, ADC_RESOLUTION);

    // Convert ADC value to voltage
    double voltage = adc_value / pow(2, ADC_RESOLUTION) * ADC_REFERENCE_VOLTAGE;

    // Calculate the angle of the robotic arm
    double angle = asin(voltage / ROBOTIC_ARM_LENGTH);

    // Output the results
    std::cout << "ADC voltage step per second: " << adc_voltage_step_per_second << " V/s" << std::endl;
    std::cout << "ADC voltage step per nanosecond: " << adc_voltage_step_per_nanosecond << " V/ns" << std::endl;
    std::cout << "ADC frequency: " << frequency << " Hz" << std::endl;
    std::cout << "ADC value: " << adc_value << std::endl;
    std::cout << "Voltage: " << voltage << " V" << std::endl;
    std::cout << "Robotic arm angle: " << angle << " radians" << std::endl;

    return 0;
}
