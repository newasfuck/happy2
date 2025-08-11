#include <JuceHeader.h>
#include "PluginProcessor.h"

// Factory JUCE looks for
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HappyAccidentAudioProcessor();
}
