# Proyecto Motor Gráfico Direct3D 11
Este proyecto es una aplicación de ejemplo de Direct3D 11 centrada en la generación de un motor gráfico básico. Incluye una serie de componentes esenciales para la creación de gráficos en 3D en entornos de Windows. A continuación se describe el contenido del proyecto:

## Componentes del Motor Gráfico
Device y DeviceContext: Clases que encapsulan el dispositivo y el contexto de dispositivo de Direct3D, proporcionando funcionalidades para la creación y gestión de recursos de gráficos.

ShaderProgram: Clase para la gestión de programas de sombreado (vertex shaders y pixel shaders), incluyendo la carga y compilación de archivos de shader.

InputLayout: Clase que define el diseño de los datos de entrada para los shaders, especificando los formatos de los vértices.

RenderTargetView y DepthStencilView: Clases para la creación y gestión de vistas de destino de renderizado y vistas de profundidad y stencil.

SwapChain: Clase que maneja el intercambio de buffers de pantalla para la presentación de gráficos renderizados en una ventana de Windows.

SamplerState: Clase para la creación y gestión de estados de muestreo, que controlan cómo se interpolan las texturas en el proceso de renderizado.

Texture: Clase que representa una textura en Direct3D 11, incluyendo la carga desde un archivo de imagen y la creación de texturas en tiempo de ejecución.

Viewport: Clase que define la región de la ventana de renderizado en la que se dibujan los gráficos.

ModelLoader: Clase para cargar modelos 3D desde archivos en formato OBJ y convertirlos en estructuras utilizables por Direct3D.

## Uso
Para utilizar este proyecto, se requiere un entorno de desarrollo con Visual Studio y el SDK de Windows. Simplemente clone el repositorio desde GitHub y abra la solución en Visual Studio. Asegúrese de que se hayan instalado todas las dependencias necesarias y configure la solución para compilar y ejecutar el proyecto.

## Contribuciones
Las contribuciones son bienvenidas. Si desea mejorar este proyecto o agregar nuevas características para expandir su funcionalidad como motor gráfico, no dude en enviar una solicitud de extracción o abrir un problema en el repositorio de GitHub.
