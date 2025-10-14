// Copyright Epic Games, Inc. All Rights Reserved.


#include "MemorialsPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "Memorials.h"
#include "Widgets/Input/SVirtualJoystick.h"

void AMemorialsPlayerController::BeginPlay()
{
	Super::BeginPlay();


	//if (MiWidgetClass)
	//{
	//	MiWidgetInstance = CreateWidget<UUserWidget>(this, MiWidgetClass);
	//	if (MiWidgetInstance)
	//	{
	//		MiWidgetInstance->AddToPlayerScreen(0); // Puedes cambiar la prioridad si lo necesitas
	//		ACharacter* MyCharacter = GetCharacter();
	//		if (MyCharacter)
	//		{
	//			//UHealthComponent* HealthComp = MyCharacter->FindComponentByClass<UHealthComponent>();
	//			//if (HealthComp)
	//			//{
	//			//	HealthComp->SetHealthProgressBar(NuevoValor); // Pasa el valor que necesites
	//			//}
	//		}

	//	}
	//	else
	//	{
	//		UE_LOG(LogMemorials, Error, TEXT("No se pudo crear el widget personalizado."));
	//	}y
	// 
	//}

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogMemorials, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void AMemorialsPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}
