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
    //Configuring Frequency Slider
    addAndMakeVisible(frequencySlider);
    frequencySlider.setSliderStyle(juce::Slider::LinearHorizontal);
    frequencySlider.setRange(20.0f, 500.0f,1.0f);
    frequencySlider.setValue(440.0f);
    frequencySlider.setTextValueSuffix(" Hz");
    //Adding Frequency Slider Label
    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", juce::dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);
    
    //Add Frequency Slider Listener
    frequencySlider.onValueChange = [this](){
        auto freq = frequencySlider.getValue();
        audioProcessor.setFrequency(freq);
    };
    
    //Configure Gain Slider
    addAndMakeVisible(gainSlider);
    gainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    gainSlider.setRange(0.0f,1.0f,0.01f);
    gainSlider.setValue(0.01f);
    gainSlider.setTextValueSuffix(" db");
    //Adding Gain Slider Label
    addAndMakeVisible(gainLabel);
    gainLabel.setText("Decibels",  juce::dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, true);
    //Add Gain Slider Listener
    gainSlider.onValueChange = [this](){
        auto newgain = gainSlider.getValue();
        audioProcessor.setGain(newgain);
    
    //Configure Button
        addAndMakeVisible(Saw);
        Saw.setButtonText("Saw");
        Saw.onClick = [this](){
            
        };
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
    gainSlider.setBounds(100,100,getWidth() - 120, 20);
    Saw.setBounds(50, 200, 50, 20);
}
