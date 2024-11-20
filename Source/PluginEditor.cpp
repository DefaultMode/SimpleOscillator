/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Simple_OscillatorAudioProcessorEditor::Simple_OscillatorAudioProcessorEditor (Simple_OscillatorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    //Configuring Slider
    addAndMakeVisible(frequencySlider);
    frequencySlider.setSliderStyle(juce::Slider::LinearHorizontal);
    frequencySlider.setRange(20.0f, 500.0f,1.0f);
    frequencySlider.setValue(440.0f);
    frequencySlider.setTextValueSuffix(" Hz");
    //Adding Label
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", juce::dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);
    
    //Add Slider Listener
    frequencySlider.onValueChange = [this](){
        auto freq = frequencySlider.getValue();
        audioProcessor.setFrequency(freq);
    };
}

Simple_OscillatorAudioProcessorEditor::~Simple_OscillatorAudioProcessorEditor()
{
}

//==============================================================================
void Simple_OscillatorAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Simple_OscillatorAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
        frequencySlider.setBounds(100, 50, getWidth() - 120, 20);
}
