#include "MainComponent.h"

// inclusion of the rest of the code not included automatically by makefile.
#include "SliderGroup.cpp"  
#include "SliderLookAndFeel.h"

//==============================================================================
MainComponent::MainComponent() 
{   

    // setSize (1024, 800);
    setSize (myWidth, myHeight);

    // howManySeqs is set to 2 at init in MainComponent.h
    if (howManySeqs > 0)  
    {
        for (int I = 0; I < howManySeqs; I++)
        {
            auto y = y0 + seqH * I * 1.5; // vertical position.
            
            sequencers.add(new SliderGroup());                       
            sequencers[I]->setName(juce::String(I));
            sequencers[I]->realise(8 * (I + 1));

            addAndMakeVisible(sequencers[I]);

            sequencers[I]->setBounds(x0, y, seqW, seqH);
        }
    } 
    else
    {
        addAndMakeVisible(seq0);
        seq0.setBounds(50, 50, 650, 200);
        seq0.setName("Seq0");
    }
    
    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

// ====
MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // nothing here for now.
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // nothing here for now.
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    int stepx = 100;
    int stepy = 100;
    int divx = 10;
    int divy = 10;

    {
        auto xf = getWidth();

        for (int J = 0; J * divy < myHeight; J++ )
        {
            auto y = J * divy;

            if ((float)(y % stepy) < 0.01)
            {
                g.setColour (juce::Colours::greenyellow);
                g.drawLine(0, y, xf, y, 1);
            } 
            else
            {
                g.setColour (juce::Colours::green);
                g.drawLine(0, y, xf, y, 1);
            }
            
        }
        auto yf = getHeight();

        for (int I = 0; I * divx < myWidth; I++ )
        {
            auto x = I * divx;

            if ((float)(x % stepx) < 0.01)
            {                
                g.setColour (juce::Colours::greenyellow);
                g.drawLine(x, 0, x, yf, 1);
            } 
            else
            {
                g.setColour (juce::Colours::green);
                g.drawLine(x, 0, x, yf, 1);
            }
        }     
    }
}

void MainComponent::resized()
{
    myWidth = getWidth();
    myHeight = getHeight();
}

// eof .-