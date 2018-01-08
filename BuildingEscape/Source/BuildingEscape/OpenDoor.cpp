// Copyright Jacob Temple 2018

#include "OpenDoor.h"
#include "GameFramework/Actor.h"




// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	
	
	// ...
	
}

void UOpenDoor::OpenDoor()
{
	AActor* owner = GetOwner();

	FRotator newRotator = owner->GetActorRotation();
	newRotator.Yaw = OpenAngle;
	owner->SetActorRotation(newRotator);
	UE_LOG(LogTemp, Warning, TEXT("Rotation is %s"), *newRotator.ToString());
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// Poll the trigger volume
	if (PressurePlate->IsOverlappingActor(OpenDoorActor)) {
		// if the opendooractor is in the volume
		OpenDoor();
	}
	// ...
}

