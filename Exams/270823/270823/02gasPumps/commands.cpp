#include "commands.h"
#include "command.h"
#include <string>
#include <algorithm>

// --- EndCommand Implementation ---
void EndCommand::process(void) {
    outputTicks(std::cout) << ": Final gas quantity: " << GasReservoir::get().getQuantity() << " kg3" << std::endl;
}

// --- InitCommand Implementation ---
InitCommand::InitCommand(std::istream& istr) : Command(istr) {
    istr >> initQ;
}

void InitCommand::process(void) {
    GasReservoir::get().setQuantity(initQ);
    outputTicks(std::cout) << ": Gas quantity: " << GasReservoir::get().getQuantity() << " kg3" << std::endl;
}

InitCommand::~InitCommand() {}

// --- InCommand Implementation ---
InCommand::InCommand(std::istream& istr) : TwoParametersCommand(istr) {}

void InCommand::process(void) {
    int quantityToAdd = getPar1();
    int hoursToPump = getPar2();
    int addedAmount = quantityToAdd * hoursToPump;

    GasReservoir::get().addCycles(hoursToPump);
    GasReservoir::get().setQuantity(GasReservoir::get().getQuantity() + addedAmount);

    outputTicks(std::cout) << ": Pumping in " << quantityToAdd << " kg3 for "
        << hoursToPump << " hours, remaining "
        << GasReservoir::get().getQuantity() << " kg3" << std::endl;
}

InCommand::~InCommand() {}

// --- OutCommand Implementation ---
OutCommand::OutCommand(std::istream& istr) : TwoParametersCommand(istr) {}

void OutCommand::process(void) {
    int quantityToDeliver = getPar1();
    int hoursToDeliver = getPar2();
    int actualDeliveryAmount = quantityToDeliver * hoursToDeliver;

    // Always add cycles as the command takes time.
    GasReservoir::get().addCycles(hoursToDeliver);

    int currentQuantity = GasReservoir::get().getQuantity();

    if (currentQuantity == 0) {
        // If tank was already empty, this GASOUT command prints the empty status.
        // This is for Example 1's "GASOUT 1 1" case.
        outputTicks(std::cout) << ": Gas Storage Empty." << std::endl;
    }
    else { // currentQuantity > 0
        if (currentQuantity >= actualDeliveryAmount) {
            // Sufficient gas to deliver
            GasReservoir::get().setQuantity(currentQuantity - actualDeliveryAmount);
            outputTicks(std::cout) << ": Delivering out " << actualDeliveryAmount << " kg3, remaining "
                << GasReservoir::get().getQuantity() << " kg3" << std::endl;
        }
        else {
            // Not enough gas, deliver all available and calculate shortage. Tank becomes empty.
            int shortage = actualDeliveryAmount - currentQuantity;
            int deliveredAmount = currentQuantity;
            GasReservoir::get().setQuantity(0); // Tank becomes empty

            outputTicks(std::cout) << ": Delivering out " << deliveredAmount << " kg3 (shortage "
                << shortage << " kg3), remaining 0 kg3" << std::endl;
            // IMPORTANT: No "Gas Storage Empty." output here, as the *next* GASOUT or DEMAND will handle it.
        }
    }
}

OutCommand::~OutCommand() {}

// --- DemandCommand Implementation ---
DemandCommand::DemandCommand(std::istream& istr) : TwoParametersCommand(istr) {}

void DemandCommand::process(void) {
    int quantityDemanded = getPar1();
    int hoursOfDemand = getPar2();
    int demandAmount = quantityDemanded * hoursOfDemand;

    // DEMAND command does NOT take time to execute, so does not add cycles.

    int currentQuantity = GasReservoir::get().getQuantity();

    outputTicks(std::cout) << ": "; // Start with Hour NNNN:

    if (currentQuantity == 0) {
        // If tank is empty, this DEMAND command prints the empty status with "CHECK:".
        std::cout << "CHECK: Gas Storage Empty." << std::endl;
    }
    else if (currentQuantity >= demandAmount) {
        std::cout << "CHECK: OK." << std::endl;
    }
    else {
        int shortage = demandAmount - currentQuantity;
        int availabilityPerHour = 0;
        if (hoursOfDemand > 0) {
            availabilityPerHour = currentQuantity / hoursOfDemand;
        }
        std::cout << "CHECK: Shortage of " << shortage << ": availability "
            << availabilityPerHour << " for " << hoursOfDemand << " hours" << std::endl;
    }
}

DemandCommand::~DemandCommand() {}