#include "PluginProcessor.h"

// The one symbol the JUCE wrappers need at link time.
// RAW POINTER. Exactly this name & signature.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HappyAccidentAudioProcessor();
}
