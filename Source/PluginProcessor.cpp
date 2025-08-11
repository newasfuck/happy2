// Minimal processor placeholder
#include "PluginProcessor.h"

// JUCE looks for this at link time for every wrapper (AU/VST3).
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HappyAccidentAudioProcessor();
}
