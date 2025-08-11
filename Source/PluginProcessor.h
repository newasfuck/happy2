#pragma once
#include <JuceHeader.h>

// Minimal, working processor
class HappyAccidentAudioProcessor : public juce::AudioProcessor
{
public:
    HappyAccidentAudioProcessor() :
        juce::AudioProcessor (BusesProperties()
            .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
            .withOutput ("Output", juce::AudioChannelSet::stereo(), true)) {}
    ~HappyAccidentAudioProcessor() override = default;

    // Basics
    const juce::String getName() const override { return "HappyAccident"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    // Programs (not used)
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int) override {}
    const juce::String getProgramName (int) override { return {}; }
    void changeProgramName (int, const juce::String&) override {}

    // Prepare/Process
    void prepareToPlay (double, int) override {}
    void releaseResources() override {}
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override
    {
        return layouts.getMainInputChannelSet()  == juce::AudioChannelSet::stereo()
            && layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
    }
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midi) override
    {
        juce::ignoreUnused (midi);
        // pass-through (no crash, silent success)
        for (int ch = getTotalNumInputChannels(); ch < getTotalNumOutputChannels(); ++ch)
            buffer.clear (ch, 0, buffer.getNumSamples());
    }

    // Editor
    bool hasEditor() const override { return false; }
    juce::AudioProcessorEditor* createEditor() override { return nullptr; }

    // State
    void getStateInformation (juce::MemoryBlock& dest) override { dest.setSize (0); }
    void setStateInformation (const void*, int) override {}
};
