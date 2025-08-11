#include <JuceHeader.h>
#include "PluginProcessor.h"

// JUCE expects a RAW POINTER here, not std::unique_ptr.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HappyAccidentAudioProcessor();
}
