/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Simple_OscillatorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Simple_OscillatorAudioProcessorEditor (Simple_OscillatorAudioProcessor&);
    ~Simple_OscillatorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Simple_OscillatorAudioProcessor& audioProcessor;
    juce::Slider frequencySlider;
    juce::Label frequencyLabel;
    juce::Slider gainSlider;
    juce::Label gainLabel;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Simple_OscillatorAudioProcessorEditor)
};
