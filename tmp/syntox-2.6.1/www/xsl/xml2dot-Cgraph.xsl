<?xml version="1.0" encoding="ISO-8859-1"?>

<xsl:stylesheet version="1.0"
		xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  
  <xsl:output method="text" encoding="UTF-8" omit-xml-declaration="yes"/>
  
  <xsl:param name="idForest">none</xsl:param>
  <xsl:param name="cs">csback.php</xsl:param>
  <xsl:param name="fs">fsback.php</xsl:param>
  
  <!--##################################################
      #
      ##################################################-->
  <xsl:template match="/ROOT">
    <xsl:text>digraph L {
    </xsl:text>
    <xsl:text>ordering=out;
    </xsl:text>
    <xsl:text>center="true";
    </xsl:text>
    <xsl:text>__BASE__ [shape=&quot;plaintext&quot;, label=&quot;&quot;];</xsl:text>
    <xsl:apply-templates select="//FOREST[@id]"/>
    <xsl:apply-templates select="//NODE"/>
    <xsl:text>}</xsl:text>
  </xsl:template>
  
  <!--##################################################
      #
      ##################################################-->
  <xsl:template match="FOREST[@empty='no']">
    <xsl:text>F_</xsl:text><xsl:value-of select="@id"/><xsl:text> [</xsl:text>
    <xsl:choose>
      <xsl:when test="@leaf='yes'">
	<xsl:text>shape=&quot;plaintext&quot;, fontname=&quot;Times-Roman&quot;, fontsize=&quot;16&quot;, label=&quot;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
	<xsl:text>shape=&quot;egg&quot;, height=&quot;0&quot;, width=&quot;0&quot;, label=&quot;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>

    <xsl:if test="ARG/@code">
      <xsl:value-of select="ARG/@code"/><xsl:text>\n</xsl:text>
    </xsl:if>
<!--
    <xsl:if test="ARG/@codeForm">
      <xsl:value-of select="ARG/@codeForm"/><xsl:text>\n</xsl:text>
    </xsl:if>
-->
    <xsl:if test="OUTPUT/S">
      <xsl:for-each select="OUTPUT/S">
	<xsl:text>&amp;nbsp;&amp;quot;</xsl:text>
	<xsl:value-of select="text()"/>
	<xsl:text>&amp;quot;&amp;nbsp;\n</xsl:text>
      </xsl:for-each>
    </xsl:if>

    <!-- -->
    <xsl:text> [</xsl:text><xsl:value-of select="@from"/><xsl:text>-</xsl:text><xsl:value-of select="@to"/><xsl:text>]</xsl:text> 
    <!-- -->

    <xsl:text>&quot;</xsl:text> 

    <xsl:if test="@color">
      <xsl:text>,style=&quot;filled&quot;,fillcolor=&quot;</xsl:text><xsl:value-of select="@color"/><xsl:text>&quot;</xsl:text>
    </xsl:if>

    <xsl:if test="ARG/FS">
      <xsl:text>,URL=&quot;</xsl:text>
      <xsl:value-of select="$fs"/><xsl:text>?idFS=</xsl:text><xsl:value-of select="ARG/FS/@id"/>
      <!--<xsl:text>&amp;conf=</xsl:text><xsl:value-of select="$conf"/>-->
      <xsl:text>&quot;</xsl:text>
    </xsl:if>

<!--
    <xsl:choose>
      <xsl:when test="@id=$idForest">
      <xsl:text>,style=&quot;filled&quot;,fillcolor=&quot;red&quot;</xsl:text>
      </xsl:when>
      <xsl:otherwise>
	<xsl:text>,style=&quot;bold&quot;</xsl:text>
      </xsl:otherwise>
    </xsl:choose>
-->
    <xsl:text>];</xsl:text>
    <xsl:variable name="id"><xsl:value-of select="@id"/></xsl:variable>
    <xsl:for-each select="NODE">
      <xsl:text>F_</xsl:text><xsl:value-of select="$id"/>
      <xsl:text> -> </xsl:text>
      <xsl:text>N_</xsl:text><xsl:value-of select="@id"/>
      <xsl:text> [arrowsize=&quot;1&quot;, arrowhead=&quot;none&quot;, label=&quot;</xsl:text>
      <xsl:text>&quot;];</xsl:text>
    </xsl:for-each>
  </xsl:template>
  
  <!--##################################################
      #
      ##################################################-->
  <xsl:template match="NODE">
    <xsl:text>N_</xsl:text><xsl:value-of select="@id"/>
    <xsl:text> [</xsl:text>
    <xsl:text>label=&quot;</xsl:text>
    <!--<xsl:text></xsl:text><xsl:value-of select="@id"/>-->
    <!-- -->
    <xsl:if test="OUTPUT/S">
      <xsl:text>OUTPUT: </xsl:text>
      <xsl:for-each select="OUTPUT/S">
	<xsl:text>&amp;nbsp;&amp;quot;</xsl:text>
	<xsl:value-of select="text()"/>
	<xsl:text>&amp;quot;&amp;nbsp;\n</xsl:text>
      </xsl:for-each>
    </xsl:if>
    <!-- -->
    <xsl:text>&quot;, shape=&quot;box&quot;, height=&quot;0.1&quot;, width=&quot;0.1&quot;</xsl:text>
    <xsl:if test="@color">
      <xsl:text>,style=&quot;filled&quot;,fillcolor=&quot;</xsl:text><xsl:value-of select="@color"/><xsl:text>&quot;</xsl:text>
    </xsl:if>
    <xsl:text>];</xsl:text>
    
    <xsl:variable name="id"><xsl:value-of select="@id"/></xsl:variable>
    <xsl:for-each select="SON[@empty='no']">
      <xsl:variable name="position" select="position()"/>
      <xsl:text>N_</xsl:text><xsl:value-of select="$id"/>
      <xsl:text> -> </xsl:text>
      <xsl:text>F_</xsl:text><xsl:value-of select="@idref"/>
      <xsl:text> [color=&quot;green&quot;, label=&quot;</xsl:text><xsl:value-of select="$position"/><xsl:text>&quot;];
</xsl:text>
    </xsl:for-each>
  </xsl:template>
  
  <!--##################################################
      #
      ##################################################-->
  <xsl:template match="*|text()">
  </xsl:template>
  
</xsl:stylesheet>
