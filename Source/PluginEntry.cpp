#include <JuceHeader.h>
#include "PluginProcessor.h"

// JUCE needs this to instantiate your processor for each wrapper (AU/VST3).
std::unique_ptr<juce::AudioProcessor> JUCE_CALLTYPE createPluginFilter()
{
    return std::make_unique<HappyAccidentAudioProcessor>();
}
