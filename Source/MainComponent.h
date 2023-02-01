#pragma once

#include <JuceHeader.h>
#include "SliderGroup.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:

    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    const long unsigned int howManySeqs{7};

    juce::OwnedArray<SliderGroup> sequencers;

    int  myWidth = 800;
    int  myHeight = 600;

    // Sequencers.
    int x0{100};     //
    int y0{100};     //
    int seqW{400};    
    int seqH{60}; 

    SliderGroup seq0;
        
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

// eof.-